import React, { useEffect, useState, useContext} from 'react';
import { FlatList, StyleSheet, Text, View, Image, SafeAreaView, StatusBar, Dimensions, TouchableOpacity, ScrollView } from 'react-native';
import { MaterialCommunityIcons, AntDesign } from '@expo/vector-icons';

import AddButton from '../components/AddButton';
import { CardContent, CardPromocao } from '../components/cards';
import CategoryButton from '../components/CategoryButton';
import colors from '../config/colors';
import NewNotification from '../components/NewNotification';

import categoriasApi from '../api/categorias';
import conteudosApi from '../api/conteudos';
import promocoesApi from '../api/promocoes';

export default function HomeScreen({navigation, route}) {

    const [categorias, setCategorias] = useState();
    const [promocoes, setPromocoes] = useState();
    const [Artigos, setArtigos] = useState();
    const [Vai, setVai] = useState();
    const [Novidades, setNovidades] = useState();
    const [Grupos, setGrupos] = useState(route.params.grupos);
    const [Eventos, setEventos] = useState(route.params.eventos);
    const [Lives, setLives] = useState(route.params.lives);

    const loadCategorias = async () => {
        const response = await categoriasApi.getCategories();
        let aux = response.data.slice(0, 5)
        aux.push(
            {
                _id: -1,
                titulo:"Ver mais",
            },
        )
        setCategorias(aux);
    };

    const getConteudo = async () => {
        const response = await conteudosApi.getConteudoByTipo("Artigo");
        setArtigos(response.data.slice(0, 5));
    };

    const getPromocoes = async () => {
        const response = await promocoesApi.getPromocoes();
        setPromocoes(response.data.slice(0, 5))
    }

    const getNewContent = async (timeDiference) => {
        const response = await conteudosApi.newContent(timeDiference);
        setNovidades(response.data.slice(0, 5))
    }

    const gonnaHappen = async (timeDiference) => {
        const response = await conteudosApi.gonnaHappen(timeDiference);
        setVai(response.data.slice(0, 5))
    }

    const run = async () =>{
        await loadCategorias();
        await getPromocoes();
        await gonnaHappen(100);
        await getNewContent(100);
        await getConteudo();
    }

    useEffect(()=> {
        run();
    },[]);

    return (
        <>
        <StatusBar style="auto" />
        <SafeAreaView style={styles.fundo}>
            <View style = {styles.topo}>
                <Image style = {styles.imgTopo} source={{                
                    uri:route.params.instituicao.imagem}}/>
                <View style = {styles.menuTopo}>
                    <Text style = {{color: colors.white}}>Que bom te ver, {route.params.nome} ;)</Text>
                    <View style = {styles.menuTopoLateral}>
                        <TouchableOpacity activeOpacity={0.7} onPress={()=> navigation.navigate("NotificationsScreen", {params: [...Eventos, ...Lives]})}>
                            <MaterialCommunityIcons name="bell-outline" size={24} color={colors.white} />   
                            <NewNotification tamanho="1.5"
                                           cor="purple" 
                                           top="-60%"
                                           right="-60%"/>
                        </TouchableOpacity>         
                        <TouchableOpacity activeOpacity={0.7} onPress={()=> navigation.navigate("MessagesScreen", {params: Grupos} )}>
                            <AntDesign name="message1" size={21} color={colors.white} />
                            <NewNotification tamanho="1.7"
                                           numero="100"
                                           cor="purple"
                                           corFont="white"
                                           top="-60%"
                                           right="-65%" />
                        </TouchableOpacity>
                    </View>
                </View>
            </View>
            <ScrollView showsVerticalScrollIndicator={false} style={styles.conteudo}>
                <View >
                    <View style={styles.categoria}>
                        <FlatList
                            contentContainerStyle={{paddingLeft: Dimensions.get("window").width*0.025}}
                            showsHorizontalScrollIndicator={false}
                            horizontal={true}
                            data={categorias}
                            keyExtractor={categorias => categorias._id.toString()}
                            renderItem={({item}) => <CategoryButton
                                                        title={item.titulo}
                                                        cor={item.cor}
                                                        comprimento={25}
                                                        altura={15}
                                                        imagem={(require("../assets/brain.png"))}
                                                        onPress={"CategoryScreen"}
                                                        params={ {"user" : route.params._id, "id" : item._id}}
                                                        />}
                        />
                        
                    </View>
                </View>
                <View>
                    <View style={styles.linha}>
                        <Text style={styles.titulo}>Promoções incríveis!!</Text>
                        <Text onPress={()=>console.log()} style={styles.verMais}>Ver mais</Text>
                    </View>
                    <View style={styles.cardPromo}>
                        <FlatList
                            contentContainerStyle={{paddingLeft: Dimensions.get("window").width*0.025}}
                            showsHorizontalScrollIndicator={false}
                            horizontal={true}
                            data={promocoes}
                            keyExtractor={promocoes => promocoes._id.toString()}
                            renderItem={({item}) => <CardPromocao
                                                        titulo={item.titulo}
                                                        imagem={item.imagem}
                                                        estabelecimento={item.estabelecimento}
                                                        validade={item.validade}
                                                        posicaoImg="-73%"
                                                        posicaoCrown="930%"
                                                        tamanhoCard={70}
                                                        />}
                        /> 
                    </View>
                </View>
                <View>
                    <View style={styles.linha}>
                        <Text style={styles.titulo}>Novidades</Text>
                        <Text onPress={()=>console.log()} style={styles.verMais}>Ver mais</Text>
                    </View>
                    <View style={styles.card}>
                        <FlatList
                            contentContainerStyle={{paddingLeft: Dimensions.get("window").width*0.025}}
                            showsHorizontalScrollIndicator={false}
                            horizontal={true}
                            data={Novidades}
                            keyExtractor={Novidades => Novidades._id.toString()}
                            renderItem={({item}) => <CardContent tipo={item.tipo} 
                                                                 titulo={item.titulo} 
                                                                 imagem={item.imagem} 
                                                                 conteudo={item.conteudo} 
                                                                 local={item.local}
                                                                 posicaoImg="-68%"
                                                                 criador={item.criador}
                                                                 data={item.data}
                                                                 tamanhoCard={60}
                                                                 onPress={item.tipo}
                                                                 params={ {"user" : route.params._id, "id" : item._id}}/>}
                        />  
                    </View>
                </View>
                <View>
                    <View style={styles.linha}>
                        <Text style={styles.titulo}>Artigos populares</Text>
                        <Text onPress={()=>console.log()} style={styles.verMais}>Ver mais</Text>
                    </View>
                    <View style={styles.card}>
                        <FlatList
                            contentContainerStyle={{paddingLeft: Dimensions.get("window").width*0.025}}
                            showsHorizontalScrollIndicator={false}
                            horizontal={true}
                            data={Artigos}
                            keyExtractor={Artigos => Artigos._id.toString()}
                            renderItem={({item}) => <CardContent tipo={item.tipo} 
                                                                titulo={item.titulo} 
                                                                imagem={item.imagem} 
                                                                conteudo={item.conteudo} 
                                                                criador={item.criador}
                                                                posicaoImg="-68%"
                                                                data={item.data}
                                                                tamanhoCard={60}
                                                                onPress={item.tipo}
                                                                params={{"user" : route.params._id, "id" : item._id}}/>}
                        />
                    </View>
                </View>
                <View>
                    <View style={styles.linha}>
                        <Text style={styles.titulo}>Vai rolar</Text>
                        <Text onPress={()=>console.log()} style={styles.verMais}>Ver mais</Text>
                    </View>
                    <View style={styles.card}>
                        <FlatList
                            contentContainerStyle={{paddingLeft: Dimensions.get("window").width*0.025}}
                            showsHorizontalScrollIndicator={false}
                            horizontal={true}
                            data={Vai}
                            keyExtractor={Vai => Vai._id.toString()}
                            renderItem={({item}) => <CardContent tipo={item.tipo} 
                                                                titulo={item.titulo} 
                                                                imagem={item.imagem} 
                                                                conteudo={item.conteudo} 
                                                                local={item.local}
                                                                criador={item.criador}
                                                                posicaoImg="-68%"
                                                                data={item.data}
                                                                tamanhoCard={60}
                                                                onPress={item.tipo}
                                                                params={{"user" : route.params._id, "id" : item._id}}/>}
                        />  
                    </View>
                </View>
            </ScrollView>
            <AddButton params={{"user" : route.params._id}}/>
        </SafeAreaView>
        </>
    );
}

const styles = StyleSheet.create({
    card:{
        height: Dimensions.get("window").height*0.18,
        width: "100%",
        flexDirection: "row",
        marginVertical: Dimensions.get("window").height*0.025,
    },
    cardPromo:{
        height: Dimensions.get("window").height*0.135,
        width: "100%",
        flexDirection: "row",
        marginVertical: Dimensions.get("window").height*0.025,
    },
    categoria:{
        height: Dimensions.get("window").height*0.18,
        width: "100%",
        flexDirection: "row",
        marginVertical: Dimensions.get("window").height*0.025,
    },
    conteudo:{
        height: Dimensions.get("window").height*0.737,
        marginTop: Dimensions.get("window").height*0.165,
    },
    fundo:{
        backgroundColor: colors.back, 
        width: "100%", 
        height: "100%",
    },
    imgTopo: {
        top: "-22%",
        height:"80%",
    },
    linha:{
        flexDirection: "row",
        justifyContent: "space-between",
        marginHorizontal: Dimensions.get("window").width*0.025,
    },
    menuTopo: {
        paddingLeft: "3%",
        paddingRight: "6%",
        top: "-3%",
        flexDirection: "row",
        justifyContent: "space-between",
    },
    menuTopoLateral: {
        width: "15%",
        flexDirection: "row",
        justifyContent: "space-between",
    },
    notificationMessage:{
        position: "absolute",
    },
    titulo: {
        fontSize: 18,
        fontWeight: "bold",
    },
    topo: {
        position: "absolute",
        width: "100%",
        height: "17%",
        backgroundColor: colors.green,
        elevation: 10,
    },
    verMais:{
        color: colors.green,
        fontSize: 13,
        paddingTop: "1%",
    }
});