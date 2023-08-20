import React, {useEffect, useState} from 'react';
import {View, StyleSheet, StatusBar, Dimensions, TouchableOpacity } from 'react-native';
import {Entypo, Ionicons, FontAwesome } from '@expo/vector-icons';

import AppSearch from '../components/AppSearch';
import { ContentList } from '../components/lists';
import colors from '../config/colors';

import conteudosApi from '../api/conteudos';
import promocoesApi from '../api/promocoes';

export default function ContentScreen({navigation, route}) {

    const [Lista, setLista] = useState();
    const [messages, setMessages] = useState();
    const [searchMessage, setSearchMessage] = useState(Lista);

    const getConteudo = async (tipo) => {
        const response = await conteudosApi.getConteudoByTipo(tipo);

        setMessages(response.data); 
        setSearchMessage(response.data);
    };

    const getPromocoes = async () => {
        const response = await promocoesApi.getPromocoes();

        setMessages(response.data); 
        setSearchMessage(response.data);
    }

    const run = async () =>{
        if(route.params.tipo !== "Promoções") await getConteudo(route.params.tipo.slice(0,-1)); 
        else await getPromocoes();
    }

    useEffect(()=>{
        run();
    }, [])

    return (
        <>
            <StatusBar style="auto" />
            <View style={styles.topo}>
                <TouchableOpacity activeOpacity={0.7}>
                    <Ionicons name="arrow-back" size={30} color={colors.green} onPress={()=> navigation.pop()}/>
                </TouchableOpacity>
                <View style={styles.search}>
                    <AppSearch paddingLeftIcon={"30%"}  categoria={"titulo"} messages={messages} setSearchMessage={setSearchMessage} titulo={route.params.tipo}/>
                </View>
                
                <View style={styles.menuTopo}>
                    <TouchableOpacity  activeOpacity={0.7}>
                        <Entypo  name="plus" size={30} color={colors.green} />
                    </TouchableOpacity>
                </View>
            </View>
            <ContentList tipo={route.params.tipo}
                          altura="93.5%"
                          lista={searchMessage}
                          params={route.params}/>
        </>
    );
}

const styles = StyleSheet.create({
    menuTopo:{
        flexDirection: "row",
        marginLeft: "3%",
    },
    search:{
        width: "80%",
        flexDirection: "row",
        justifyContent: "flex-end",
    },
    textoTopo:{
        color: colors.green,
        fontSize: 18,
        fontWeight: "700"
    },
    topo:{
        width: "100%",
        height: Dimensions.get("window").height*0.06,
        alignContent: "center",
        paddingHorizontal: "1.8%",
        borderColor: colors.grey,
        borderBottomWidth: 0.6,
        flexDirection: "row",
        alignItems: "center",
        backgroundColor: colors.white,
    },
})