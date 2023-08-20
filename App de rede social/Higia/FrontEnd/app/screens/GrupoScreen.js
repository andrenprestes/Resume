import React, { useEffect, useState } from 'react';
import { View, StyleSheet, StatusBar, Text, TouchableOpacity} from 'react-native';
import { MaterialIcons, Ionicons} from '@expo/vector-icons';
import colors from '../config/colors';

import userApi from '../api/users';

export default function GrupoScreen({navigation, route}) {
    const [pressed, setPressed] = useState(false);
    const [lista, setLista] = useState();

    const run = async () => {
        await userApi.verifyContent(route.params.user,"Grupo",route.params.id).then(response => {
            setPressed(response.data.existe);
            setLista(response.data.lista);
        });
    };

    const exit = async () => {
        let aux = {"grupos" : lista};
        await userApi.updateUser(route.params.user, aux).then(response=>navigation.pop());
    };

    const adicionaFavorito = () => {
        setLista([...lista, route.params.id]);
        setPressed(true);
    };

    const removeFavorito = () => {
        setLista(lista.filter(x => x !== route.params.id));
        setPressed(false);
    };

    useEffect(()=>{
        run();
    }, [])
    return (
        <>
            <StatusBar style="auto" />
            <View style={styles.container}>
                <Ionicons name="arrow-back" size={30} color={colors.green} onPress={exit}/>
                <Text>Grupo user: {route.params.user}, id: {route.params.id}</Text>
                {pressed
                ? <MaterialIcons name="favorite" size={24} color={colors.green} onPress={removeFavorito}/>
                : <MaterialIcons name="favorite-border" size={24} color={colors.green} onPress={adicionaFavorito}/>}

                <Text>{lista}</Text>
            </View>
        </>
    );
}

const styles = StyleSheet.create({
    container:{

    },
})