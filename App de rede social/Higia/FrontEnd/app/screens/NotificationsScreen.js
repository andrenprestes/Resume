import React, {useState, useEffect} from 'react';
import { FlatList, View, StyleSheet, StatusBar, Text, TouchableOpacity, Dimensions, Alert} from 'react-native';
import { Ionicons } from '@expo/vector-icons';

import colors from '../config/colors';
import { ListItemDeleteAction, ListNotifications } from '../components/lists';

import notificaçõesApi from '../api/notificações';
import conteudosApi from '../api/conteudos';

export default function NotificationsScreen({navigation, route}) {
    
    const [notificacoes, setNotificacoes] = useState([]);
    const [refreshing, setRefreshing] = useState(false);
    const [aux, setAux] = useState([]);
    const [loading, setLoading] = useState(false);
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

    const run = async () => {
    
        for (const x of route.params.params){
            let response = await notificaçõesApi.getNotificationsByConteudoId(x);
            let e = [...aux, ...response.data];
            setAux(e);
        }
        for (const x of route.params.params){
            let respo = await conteudosApi.getConteudoById(x);
            let e = [...Lista, respo.data[0]];
            setLista(e);
        }

        for (let i = 0; i < aux.length; i++){
            aux[i].tipo = Lista.find(x => x._id.toString() === aux[i].conteudoId.toString()).tipo;
            aux[i].conteudo = Lista.find(x => x._id.toString() === aux[i].conteudoId.toString()).titulo;
            aux[i].data = changeData(Lista.find(x => x._id.toString() === aux[i].conteudoId.toString()).data);
            setNotificacoes([...notificacoes, aux[i]]);
        }
        setLoading(true);
    }

    useEffect(()=>{
        run();
    }, [loading])


    const handleDelete = notificacao => {
        setNotificacoes(notificacoes.filter(m => m.id !== notificacao.id))
    }
    const createTwoButtonAlert = () =>
            Alert.alert(
            "Verificação",
            "Deseja limpar todas as notificações?",
            [
                {
                text: "Cancel", style: "cancel"
                },
                { text: "OK", onPress: () => setNotificacoes([]) }
            ]
            );

    return (
        <>
            <StatusBar style="auto" />
            <View style={styles.topo}>
                <TouchableOpacity activeOpacity={0.7}>
                    <Ionicons name="arrow-back" size={30} color={colors.green} onPress={()=> navigation.pop()}/>
                </TouchableOpacity>
                <Text style={styles.textoTopo}>Notificações</Text>
                <TouchableOpacity activeOpacity={0.7}>
                    <Text style={styles.limpar} onPress={createTwoButtonAlert}>Limpar</Text>
                </TouchableOpacity>
            </View>
            <View style={styles.mensagens}>
                <FlatList
                    data={notificacoes}
                    keyExtractor={notificacoes => notificacoes._id.toString()}
                    renderItem={({item}) => (<ListNotifications 
                                                tipo={item.tipo}
                                                conteudo={item.conteudo}
                                                data={item.data}
                                                onPress={()=>console.log()}
                                                criado="21/02/2022 10:50"
                                                renderRightActions={()=> <ListItemDeleteAction
                                                                                onPress={()=> handleDelete(item)}/>}
                                                />)}
                    ItemSeparatorComponent={()=> <View style={{width: "100%", height: 1, backgroundColor: colors.darkGrey, marginVertical: Dimensions.get("window").height*0.002}}/>}
                    refreshing={refreshing}
                    
                />
            </View>
        </>
    );
}

const styles = StyleSheet.create({
    limpar:{
        color: colors.green,
    },
    mensagens:{
        paddingBottom: "10%",
    },
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
        borderColor: colors.grey,
        borderBottomWidth: 0.6,
        flexDirection: "row",
        justifyContent: "space-between",
        alignItems: "center",
    },
})