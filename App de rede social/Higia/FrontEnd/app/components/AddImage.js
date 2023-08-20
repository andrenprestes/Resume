import React, {useEffect } from 'react';
import { View, StyleSheet, Image } from 'react-native';
import { Entypo } from '@expo/vector-icons'; 
import * as ImagePicker from 'expo-image-picker';
import * as CameraPermissions from 'expo-camera';

import colors from '../config/colors';

export default function AddImage({tamanho = 150, borderColor="black", borderRadius=tamanho/2, imageUri, onChange}) {

    const requestPermission = async () =>{
        const resultCamera = await CameraPermissions.Camera.requestCameraPermissionsAsync();
        const {granted} = await ImagePicker.requestMediaLibraryPermissionsAsync();
        if(!granted || !resultCamera.granted)
            alert('É preciso permitir o acesso para o funcionamento de todas as funções do Aplicativo!');
    }

    const selectImage = async () => {
        try {
            const result = await ImagePicker.launchImageLibraryAsync({
                mediaTypes: ImagePicker.MediaTypeOptions.Images,
                quality: 0.5,
            });
            if (!result.cancelled){
                onChange(result.uri);
            }
        } catch (error) {
            console.log("Erro lendo a imagem!");
        }
    }

    useEffect(() => {
        requestPermission();
    }, []);

    return (
        <View >
            <Image source={{uri: imageUri}} style={[styles.container, {width: tamanho, aspectRatio: 1, borderRadius: borderRadius, borderColor: colors[borderColor],}]}/>
            <View style={styles.icon}>
                <Entypo onPress={selectImage} name="camera" size={24} color={colors.white} />
            </View>
        </View>
    );
}

const styles = StyleSheet.create({
    container:{
        borderWidth: 2,
    },
    icon:{
        width: 38,
        aspectRatio: 1,
        borderRadius: 38/2,
        backgroundColor: colors.green,
        alignItems: "center",
        justifyContent:"center",
        bottom:"0%",
        right: "0%",
        position: "absolute",
    },
})