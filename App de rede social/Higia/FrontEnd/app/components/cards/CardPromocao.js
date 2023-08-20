import React, { useEffect, useState } from 'react';
import {Image, StyleSheet, View, Text, Dimensions, TouchableOpacity } from 'react-native';
import { FontAwesome5 } from '@expo/vector-icons';

import colors from '../../config/colors';
import estabelecimentosApi from '../../api/estabelecimentos';

export default function CardPromocao({titulo, estabelecimento, validade, onPress, imagem, posicaoImg, tamanhoCard, posicaoCrown}) {
    const [i, setI] = useState();
    function changeData(){
        var date = new Date(validade);
        var dd = String(date.getDate()).padStart(2, '0');
        var mm = String(date.getMonth() + 1).padStart(2, '0'); //January is 0!
        var yyyy = date.getFullYear();

        return dd + '/' + mm + '/' + yyyy;
    }

    const getEstabelecimento = async () =>{
        const response = await estabelecimentosApi.getEstabelecimentoById(estabelecimento);
        setI(response.data[0].nome)
    };

    useEffect(()=>{
        getEstabelecimento();
    }, []);

    return (
        <TouchableOpacity activeOpacity={0.7} onPress={onPress}>
            <View style={[styles.card, {width: Dimensions.get('window').width*tamanhoCard/100,}]}>
                <View style={styles.cardConteudo}>
                    <View style={styles.cardConteudoInfo}>
                        <Text numberOfLines={2} style={styles.cardConteudoTitulo}>{titulo}</Text>
                        <Text numberOfLines={1} style={styles.cardConteudoTexto}>Oferecido por {i}</Text>
                        <Text numberOfLines={1} style={styles.cardConteudoTexto}>Válido até {changeData()}</Text>
                    </View>
                    <View >
                        <FontAwesome5 style={[styles.crown, {bottom: posicaoCrown,}]} name="crown" size={16} color={colors.gold} />
                    </View>
                    
                    <View>
                        <Image style={[styles.cardImg, {right: posicaoImg}]} source={{
                            uri: imagem,
                        }}/>
                    </View>
                </View>
            </View>
        </TouchableOpacity>
    );
}

const styles = StyleSheet.create({
    card: {
        height: Dimensions.get('window').height*0.12,
        backgroundColor: colors.green,
        borderRadius: 4,
        overflow: "hidden",
        elevation: 5,
        marginRight: Dimensions.get("window").width*0.05,
        marginBottom: Dimensions.get("window").height*0.015/2,
        marginTop: Dimensions.get("window").height*0.015/2,
    },
    cardConteudo: {
        height: "58%",
        paddingLeft: "3.5%",
    },
    cardConteudoInfo: {
        marginLeft: Dimensions.get("window").width*0.042,
        marginTop: Dimensions.get("window").width*0.01,
        width: "65%",
        height: Dimensions.get('window').height*0.1,
    },
    cardConteudoTexto: {
        fontSize: 10,
        color: colors.white,
        paddingBottom: "1%"
    },
    cardConteudoTitulo: {
        fontSize: 15,
        color: colors.white,
        fontWeight: "600",
        marginBottom: "7%",
    },
    cardImg: {
        borderColor: "rgba(255, 255, 255, .8)",
        borderWidth: 2,
        width: Dimensions.get("window").width*0.25,
        aspectRatio: 1,
        borderRadius: Dimensions.get("window").width*0.25/2,
        alignContent: "flex-end",
        bottom: "130%",
    },
    crown:{
        transform: [{ rotate: '-45deg'}],
        bottom: "980%",
        left: "-16%",
    }
})
