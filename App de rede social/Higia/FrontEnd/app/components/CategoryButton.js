import React, { useEffect } from 'react';
import {Image, StyleSheet, View, Text, Dimensions, TouchableOpacity } from 'react-native';
import { Feather } from '@expo/vector-icons'; 

import colors from '../config/colors';
import { useNavigation } from '@react-navigation/native';

export default function CategoryButton({title, cor, comprimento, altura, onPress, imagem, params, key}) {
    const navigation = useNavigation();
    const imagens = {
        Esporte: require("../assets/brain.png"),
        Música: require("../assets/brain.png"),
        Dança: require("../assets/brain.png"),
        Corrida: require("../assets/brain.png"),
        Jogo: require("../assets/brain.png"),
      }

    function checkFunction(x) {
        if (Object.prototype.toString.call(x) == '[object Function]')
            return false;
        else
            return true;
    }
    
    if (title == "Ver mais"){
        return(
            <>
            <TouchableOpacity activeOpacity={0.7} onPress={()=>navigation.navigate("CategoriesScreen", {...params, title: title})}>
                <View style={[styles.categoria, {width: Dimensions.get("window").width*0.25,height: Dimensions.get("window").height*0.15}]}>
                    <View style={[styles.categoriaFundo]}>
                        <Feather name="more-horizontal" style={styles.categoriaImagem} size={60} color={colors.darkGrey} />
                    </View>
                    <Text style={styles.categoriaTipo}>{title}</Text>
                </View>
            </TouchableOpacity>
            </>
        );
    }

    return (
        <>
        <TouchableOpacity key={key} activeOpacity={0.7} onPress={checkFunction(onPress) ? ()=>navigation.navigate(onPress, {...params, title: title}): onPress}>
            <View style={[styles.categoria, {width: Dimensions.get("window").width*comprimento/100,height: Dimensions.get("window").height*altura/100}]}>
                <View style={[styles.categoriaFundo, {backgroundColor: colors[cor]}]}>
                    <Image resizeMode='contain' style={styles.categoriaImagem} source={!imagem ? imagens[title] : imagem}/>
                </View>
                <Text style={styles.categoriaTipo}>{title}</Text>
            </View>
        </TouchableOpacity>
        </>
    );
}

const styles = StyleSheet.create({
    categoria: {
        justifyContent: "center",
        alignItems: "center",
        marginRight: Dimensions.get("window").width*0.05,
        marginTop: Dimensions.get("window").height*0.01,
    },
    categoriaFundo: {
        width: "70.71%",
        aspectRatio: 1,
        borderRadius: 4,
        transform: [{ rotate: '45deg'}],
        justifyContent: "center",
        alignItems: "center",
    },
    categoriaImagem: {
        height: "90%",
        transform: [{ rotate: '-45deg'}],
    },
    categoriaTipo: {
        bottom: -Dimensions.get("window").height*0.02,
        color: colors.black,
    },
})

