import React, {useEffect, useState} from 'react';
import { FlatList, View, StyleSheet, StatusBar, Text, TouchableOpacity, Dimensions, TextInput } from 'react-native';
import { Ionicons, FontAwesome, AntDesign  } from '@expo/vector-icons';

import colors from '../config/colors';
import { ListItemDeleteAction, ListMessages } from '../components/lists';
import AppSearch from '../components/AppSearch';

import mensagensApi from '../api/mensagens';
import conteudosApi from '../api/conteudos';

export default function MessagesScreen({navigation, route}) {

    const [messages, setMessages] = useState([]);
    const [searchMessage, setSearchMessage] = useState([]);
    const [refreshing, setRefreshing] = useState(false);
    const [aux, setAux] = useState([]);
    const [loading, setLoading] = useState(false);
    const [numMesGroup, setNumMesGroup] = useState([])
    const [Lista, setLista] = useState([]);
    
    function changeData(data){
        var date = new Date(data);
        var dd = String(date.getDate()).padStart(2, '0');
        var mm = String(date.getMonth() + 1).padStart(2, '0'); 
        var yyyy = date.getFullYear();
        var hh = date.getHours();
        var min = date.getMinutes()

        return dd + '/' + mm + '/' + yyyy + " " + hh + ":" + min;
    }

    const handleDelete = message => {
        setSearchMessage(searchMessage.filter(m => m.id !== message.id))
    }   

    const run = async () => {
    
        for (const x of route.params.params){
            let response = await mensagensApi.getMessagesByGroupId(x);
            for (const y of response.data)
                y.data = changeData(y.data);
            
            let e = [...aux, response.data]
            setNumMesGroup([...numMesGroup, response.data.length])
            setAux(e);
        }
        for (const x of route.params.params){
            let respo = await conteudosApi.getConteudoById(x);
            let e = [...Lista, respo.data[0]]
            setLista(e);
        }
        aux.forEach(x => {
            x.sort(function(a,b){
                return new Date(b.data) - new Date(a.data);
            });
        })
        for (let i = 0; i < aux.length; i++){
            aux[i][0].num = numMesGroup[i];
            aux[i][0].imagem = Lista[i].imagem;
            aux[i][0].title = Lista[i].titulo;
            setMessages([...messages, aux[i][0]]);
            setSearchMessage([...messages, aux[i][0]]);
        }
        setLoading(true);
    }

    useEffect(()=>{
        run();
    }, [loading])
    

    return (
        <>
            <StatusBar style="auto" />
            <View style={styles.topo}>
                <TouchableOpacity activeOpacity={0.7}>
                    <Ionicons name="arrow-back" size={30} color={colors.green} onPress={()=> navigation.pop()}/>
                </TouchableOpacity>
                <AppSearch categoria={"title"} messages={messages} setSearchMessage={setSearchMessage} titulo={"Conversas"}/>
                
            </View>
            <View style={styles.mensagens}>
                <FlatList
                    data={searchMessage}
                    keyExtractor={searchMessage => searchMessage._id.toString()}
                    renderItem={({item}) => <ListMessages
                                                nome={item.title}
                                                imagem={item.imagem}
                                                conteudo={item.mensagem}
                                                data={item.data}
                                                numeroDeMensagens={item.num}
                                                onPress={()=>console.log()}
                                                renderRightActions={()=><ListItemDeleteAction
                                                                            onPress={()=> handleDelete(item)}/>}
                                                />}
                    refreshing={refreshing}
                />
            </View>
        </>
    );
}

const styles = StyleSheet.create({
    icon:{
        justifyContent: "flex-end",
    },
    mensagens:{
        paddingBottom: "11%",
    },
    search:{
        backgroundColor: "#f0f0f0",
        padding: "3%",
        width: "88%",
        borderTopLeftRadius: 20,
        borderBottomLeftRadius: 20,
    },
    searchBox:{
        backgroundColor: "#f0f0f0",
        alignItems: "center",
        flexDirection: "row",
        borderRadius: 20,
        margin: "1%",
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
        justifyContent: "space-between",
        alignItems: "center",
    },
})