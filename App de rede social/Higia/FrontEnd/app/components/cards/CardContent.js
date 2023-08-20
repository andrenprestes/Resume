import React, {useState, useEffect} from 'react';
import { Image, StyleSheet, View, Text, TouchableWithoutFeedback, Dimensions, TouchableOpacity} from 'react-native';
import { Entypo, AntDesign } from '@expo/vector-icons';

import colors from '../../config/colors';
import usersApi from '../../api/users';
import { useNavigation, useRoute } from '@react-navigation/native';

export default function CardContent({tipo, titulo, conteudo, imagem, data, criador, local, posicaoImg, tamanhoCard, onPress, params}) {
    const [i, setI] = useState();
    const navigation = useNavigation();
    const route = useRoute();

    function changeData(){
        var date = new Date(data);
        var dd = String(date.getDate()).padStart(2, '0');
        var mm = String(date.getMonth() + 1).padStart(2, '0'); 
        var yyyy = date.getFullYear();
        var hh = date.getHours();
        var min = date.getMinutes()

        return dd + '/' + mm + '/' + yyyy + " " + hh + ":" + min;
    }

    const getUser = async (id) => {
        return await usersApi.getUserById(id);
    }

    const run = async () => {
        const response = await getUser(criador);
        setI(response.data[0].nome);
    }

    useEffect(()=>{
        criador ? run() : null;
    }, []);
    
    switch(tipo){
        case "Grupo" :
            var card = (
            <View style={styles.cardFim1}>
                <Entypo name="location-pin" size={15} color={colors.purple} />
                <Text style={styles.cardFimTexto}>{ local}</Text>
            </View>
            );
            break;
        
        case "Evento" :
            var card = (
            <View style={styles.cardFim2}>
                <View style={styles.cardFimAlinhar}>
                    <AntDesign name="calendar" size={15} color={colors.purple} />
                    <Text style={styles.cardFimTexto}> { changeData()}</Text>
                </View>
                <View style={styles.cardFimAlinhar}>
                    <Entypo name="location-pin" size={15} color={colors.purple} />
                    <Text style={styles.cardFimTexto}>{ local}</Text>
                </View>
            </View>
            );
            break;

        case "Artigo" :
            var card = (
            <View style={styles.cardFim1}>
                <Image style={styles.autorImg} source={require("../../assets/stonks-meme.jpg")}/>
                <Text style={styles.cardFimTexto}>{ i}</Text>
            </View>
            );
            break;

        case "Live" :
            var card = (
            <View style={styles.cardFim2}>
                <View style={styles.cardFimAlinhar}>
                    <AntDesign name="calendar" size={15} color={colors.purple} />
                    <Text style={styles.cardFimTexto}> { changeData()}</Text>
                </View>
                <View style={[styles.cardFimAlinhar, {right: "-3.5%"}]}>
                    <Image style={styles.autorImg} source={require("../../assets/stonks-meme.jpg")}/>
                    <Text style={styles.cardFimTexto}> { i}</Text>
                </View>
            </View>
            );
            break;
    }
    
    return (
        <TouchableOpacity activeOpacity={0.7} onPress={()=>navigation.navigate(onPress, params)}>
            <View style={[styles.card, {width: Dimensions.get('window').width*tamanhoCard/100,}]}>
                <View style={styles.cardTopo}>
                    <Text style={styles.cardTipo}>{tipo}</Text>
                </View>
                <View style={styles.cardConteudo}>
                    <View style={styles.cardConteudoInfo}>
                        <Text numberOfLines={2} style={styles.cardConteudoTitulo}>{titulo}</Text>
                        <Text numberOfLines={3} style={styles.cardConteudoTexto}>{conteudo}</Text>
                    </View>
                    <View>
                        <Image style={[styles.cardImg, {right: posicaoImg}]} source={{
                            uri: imagem,
                        }}/>
                    </View>
                </View>
                {card}
            </View>
        </TouchableOpacity>
    );
}

const styles = StyleSheet.create({
    autorImg: {
        width: Dimensions.get("window").width*0.04,
        aspectRatio: 1,
        borderRadius: Dimensions.get("window").width*0.04/2,
    },
    card: {
        height: Dimensions.get('window').height*0.165,
        backgroundColor: colors.white,
        borderColor: colors.grey,
        borderWidth: 0.5,
        borderRadius: 4,
        overflow: "hidden",
        elevation: 5,
        marginRight: Dimensions.get("window").width*0.05,
        marginBottom: Dimensions.get("window").height*0.015/2,
        marginTop: Dimensions.get("window").height*0.015/2,
    },
    cardConteudo: {
        width: "100%",
        height: Dimensions.get('window').height*0.1,
        paddingLeft: Dimensions.get('window').width*0.018,
        paddingRight: Dimensions.get('window').width*0.018,
        bottom: "5%",
    },
    cardConteudoInfo: {
        width: "67%",
        height: "90%",
    },
    cardConteudoTexto: {
        fontSize: 13,
        color: colors.grey,
    },
    cardConteudoTitulo: {
        fontSize: 14,
        fontWeight: "700",
    },
    cardFim1:{
        flexDirection: 'row',
        justifyContent: "flex-end",
        marginRight: "3.5%",
        bottom: "2%",
    },
    cardFim2:{
        flexDirection: 'row',
        justifyContent: "space-between",
        marginHorizontal: "3.5%",
        paddingRight: "3.5%",
        bottom: "2%",
    },
    cardFimAlinhar:{
        flexDirection: 'row',
    },
    cardFimTexto:{
        color: colors.grey,
        fontSize: 10,
    },
    cardImg: {
        width: Dimensions.get("window").width*0.28,
        aspectRatio: 1,
        borderRadius: Dimensions.get("window").width*0.28/2,
        bottom: "110%",
    },
    cardTipo: {
        color: colors.green,
        fontSize: 11,
        paddingLeft: Dimensions.get('window').width*0.018,
        paddingTop: Dimensions.get('window').height*0.01,
    },
    cardTopo: {
        width: "100%",
        height: Dimensions.get('window').height*0.045,
    },
})