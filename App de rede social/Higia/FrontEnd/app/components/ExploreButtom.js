import React from 'react';
import { Image, Text, StyleSheet, View, Dimensions, TouchableOpacity } from 'react-native';
import colors from '../config/colors';
import { FontAwesome5 } from '@expo/vector-icons';
import { useNavigation } from '@react-navigation/native';

export default function ExploreButtom({tipo, altura, largura, cor, imagem, params}) {
    const navigation = useNavigation();
    return (
        <TouchableOpacity activeOpacity={0.7} onPress={() => navigation.navigate("ContentScreen", {...params, tipo: tipo })}>
            <View style={[styles.botao, {
                width: Dimensions.get("window").width*largura/100,
                height: Dimensions.get("window").height*altura/100,
                backgroundColor: colors[cor],
            }]}>
                <View style={{ justifyContent:"flex-end"}}>
                    <Text style={styles.texto}>{tipo}</Text>    
                </View>
                <View >
                    {tipo =="Promoções" && <FontAwesome5 style={[styles.crown]} name="crown" size={16} color={colors.gold} />}
                    <Image resizeMode='contain' style={styles.imagem} source={{uri:imagem}}/>   
                </View>
            </View>
        </TouchableOpacity>
    );
}

const styles = StyleSheet.create({
    botao: {
        marginRight: Dimensions.get("window").width*0.03,
        marginVertical: Dimensions.get("window").width*0.015,
        borderRadius: 5,
        paddingHorizontal: "3%",
        flexDirection: "row",
        justifyContent: "space-between",
        alignItems: "flex-end",
    },
    crown:{
        transform: [{ rotate: '-45deg'}],
        left: "-120%",
        top: "-46%",
        position: "absolute"
    },
    imagem: {
        height: Dimensions.get("window").height*0.09,
        width: Dimensions.get("window").width*0.2,
    },
    texto: {
        color: colors.white,
        fontSize: 19,
        paddingBottom: "5%",
    },
})