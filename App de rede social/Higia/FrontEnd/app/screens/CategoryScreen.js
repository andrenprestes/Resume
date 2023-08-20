import React, { useEffect, useState } from 'react';
import { View, StyleSheet, Text, TouchableOpacity  } from 'react-native';
import { createMaterialTopTabNavigator } from '@react-navigation/material-top-tabs';
import { useNavigation, useRoute } from '@react-navigation/native';
import { Ionicons, AntDesign  } from '@expo/vector-icons';

import categoriasApi from '../api/categorias';
import { ContentList } from '../components/lists';
import colors from '../config/colors';
import conteudosApi from '../api/conteudos';
import promocoesApi from '../api/promocoes';

const Tab = createMaterialTopTabNavigator();
const CategoryNavigator = () => {
    const route = useRoute();
    const navigation = useNavigation();

    const [Artigos, setArtigos] = useState();
    const [Grupo, setGrupo] = useState();
    const [Eventos, setEventos] = useState();
    const [Lives, setLives] = useState();
    const [Promocoes, setPromocoes] = useState();
    const [Categoria, setCategoria] = useState();
    
    const getConteudo = async (tipo, idCategory) => {
        const response = await conteudosApi.getConteudoByTipoCategory(tipo, idCategory);
        switch(tipo){
            case "Artigo":
                setArtigos(response.data);
                break;
            
            case "Grupo":
                setGrupo(response.data);
                break;
            
            case "Evento":
                setEventos(response.data);
                break;

            case "Live":
                setLives(response.data);
                break;
        }
    };

    const getPromocoes = async () => {
        const response = await promocoesApi.getPromocoes();
        setPromocoes(response.data)
    }

    const getCategoryByName = async (Name) => {
        const response = await categoriasApi.getCategoryByName(Name);
        await getConteudo("Artigo", response.data[0]._id.toString());
        await getConteudo("Grupo", response.data[0]._id.toString());
        await getConteudo("Evento", response.data[0]._id.toString());
        await getConteudo("Live", response.data[0]._id.toString());
    }

    const run = async () =>{
        await getCategoryByName(route.params.title);
        await getPromocoes();
    }

    useEffect(()=>{
        run();
    }, []);

    return(
    <>
    <View style={styles.topo}>
        <TouchableOpacity activeOpacity={0.7}>
            <Ionicons name="arrow-back" size={30} color={colors.green} onPress={()=> navigation.goBack()}/>
        </TouchableOpacity>
        <Text style={styles.textoTopo}>{route.params.title}</Text>
        <TouchableOpacity activeOpacity={0.7}>
            <AntDesign  name="star" size={25} color={colors.green} />
        </TouchableOpacity>
    </View>
    <Tab.Navigator 
        screenOptions={{
            tabBarActiveTintColor: "#53B146",
            tabBarInactiveTintColor: "#949494",
            tabBarScrollEnabled: true,
            tabBarItemStyle: {
              width: 108.00000000000001
            },
            tabBarIndicatorStyle: {
              borderBottomWidth: 2,
              borderBottomColor: "#53B146"
            },
            tabBarStyle: {
              backgroundColor: "#fff"
            }
          }}>
        <Tab.Screen name="Artigos"  children={()=><ContentList tipo="Artigos"
                                                                altura="100%"
                                                                lista={Artigos}
                                                                params={route.params}/>}/>
        <Tab.Screen name="Grupos" children={()=><ContentList tipo="Grupos"
                                                                altura="100%"
                                                                lista={Grupo}
                                                                params={route.params}/>} />
        <Tab.Screen name="Eventos" children={()=><ContentList tipo="Eventos"
                                                                altura="100%"
                                                                lista={Eventos}
                                                                params={route.params}/>} />
        <Tab.Screen name="Lives" children={()=><ContentList tipo="Lives"
                                                                altura="100%"
                                                                lista={Lives}
                                                                params={route.params}/>} />
        <Tab.Screen name="Promoções" children={()=><ContentList tipo="Promoções"
                                                                altura="100%"
                                                                lista={Promocoes}
                                                                params={route.params}/>} />
    </Tab.Navigator>
    </>
)};

export default function CategoryScreen({}) {
    return (
        <>
            <CategoryNavigator/>
        </>
    );
}

const styles = StyleSheet.create({
    textoTopo:{
        color: colors.green,
        fontSize: 18,
        fontWeight: "700"
    },
    topo:{
        width: "100%",
        height: "6%",
        alignContent: "center",
        paddingHorizontal: "1.8%",
        flexDirection: "row",
        justifyContent: "space-between",
        alignItems: "center",
        backgroundColor: colors.white,
    },
})
