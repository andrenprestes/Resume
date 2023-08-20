import React, {useEffect, useState} from 'react';
import { FlatList, View, StyleSheet, StatusBar, Text, TouchableOpacity, Dimensions, Button } from 'react-native';

import CategoryButton from '../components/CategoryButton';
import Check from '../components/Check';
import colors from '../config/colors';
import categoriasApi from '../api/categorias';
import userApi from '../api/users';

export default function InterestScreen({navigation, route}) {

    const [a, setA] = useState(route.params);
    const [b, setB] = useState();
    const [categorias, setCategorias] = useState([]);
    const [initialCategories, setInitialCategorias] = useState();

    const loadCategorias = async () => {
        const response = await categoriasApi.getCategories();
        setInitialCategorias(response.data);
    };

    useEffect(()=> {
        loadCategorias();
    },[]);

    
    function addCategorias(){
        
        a['email'] = a.values.email;
        a['imagem'] = a.values.imagem;

        a['instituicao'] = a.values.instituicao;

        a['nome'] = a.values.nome;
        a['senha'] = a.values.senha;
        a['categorias'] = categorias;
        a['grupos'] = [];
        a['eventos'] = [];
        a['lives'] = [];
        a['artigos'] = [];
        delete a["values"];
        
        var b = {...a};
        b['instituicao'] = a.instituicao._id;
        
        userApi.createUser(b).then(() => {
            setA(a);
            navigation.navigate("MainContent", {params: a});
        })
    }

    return (
        <>
            <StatusBar style="auto" />
            <View style={styles.topo}>
                <Text style={styles.textoTopo}>Selecionar interesses</Text>
                <TouchableOpacity activeOpacity={0.7}>
                    <Text style={styles.pular}  onPress={()=> {addCategorias()}}>Pular</Text>
                </TouchableOpacity>
            </View>
            <View>
                <Text style={styles.tituloMenu}>Escolha os tópicos que te interessam</Text>
                <Text style={styles.textoMenu}>Você pode mudar essas configurações a qualquer momento no seu perfil</Text>
            </View>
            <View style={styles.categorias}>
                <FlatList
                    data={initialCategories}
                    keyExtractor={initialCategories => initialCategories._id.toString()}
                    numColumns={3}
                    renderItem={({item}) => 
                    (<View style={!categorias.includes(item._id) ? {opacity: 0.7} : null}>
                        <CategoryButton 
                            title={item.titulo}
                            comprimento={29}
                            imagem={(require("../assets/brain.png"))}
                            altura={19}
                            onPress={()=>{!categorias.includes(item._id) ? setCategorias(arr => [...arr, item._id]) : setCategorias(categorias.filter(m => m !== item._id))}}
                            />
                        <View style={{position: "absolute", overflow: "visible"}}>
                            {categorias.includes(item._id) && <Check tamanho={24} cor="purple" top={Dimensions.get("window").height*0.01} right={-Dimensions.get("window").width*0.19}/>}
                        </View>
                    </View>)}
                    
                />
            </View>
            <View style={styles.botao}>
                <Button  color={colors.green} title='Finalizar' onPress={()=> {addCategorias()}}/>
            </View>
            
        </>
    );
}

const styles = StyleSheet.create({
    botao:{
        paddingHorizontal: "3%",
    },
    categorias:{
        height: "72%",
        marginTop: "3%",
        marginLeft: "1.5%",
    },
    pular:{
        color: colors.green,
    },
    textoTopo:{
        color: colors.green,
        fontSize: 18,
        fontWeight: "700",
    },
    textoMenu:{
        color: colors.darkGrey,
        fontSize: 13,
        textAlign: "center",
        paddingHorizontal: "3%",
    },
    tituloMenu:{
        color: colors.black,
        fontSize: 18,
        fontWeight: "600",
        textAlign: "center",
        marginVertical: "3%",
    },
    topo:{
        width: "100%",
        height: "6%",
        alignContent: "center",
        paddingHorizontal: "5%",
        borderColor: colors.grey,
        borderBottomWidth: 0.6,
        flexDirection: "row",
        alignItems: "center",
        backgroundColor: "white",
        justifyContent: "space-between"
    },
})
