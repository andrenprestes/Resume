import React, {useEffect, useState} from 'react';
import { FlatList, View, StyleSheet, StatusBar, Text, TouchableOpacity } from 'react-native';
import { Ionicons } from '@expo/vector-icons';
import { useNavigation } from '@react-navigation/native';

import CategoryButton from '../components/CategoryButton';
import colors from '../config/colors';
import categoriasApi from '../api/categorias';

export default function CategoriesScreen({route}) {
    const navigation = useNavigation();

    const [initialCategories, setInitialCategorias] = useState();

    const loadCategorias = async () => {
        const response = await categoriasApi.getCategories();
        setInitialCategorias(response.data);

    };

    useEffect(()=> {
        loadCategorias();
    },[]);

    return (
        <>
            <StatusBar style="auto" />
            <View style={styles.topo}>
                <TouchableOpacity activeOpacity={0.7}>
                    <Ionicons name="arrow-back" size={30} color={colors.green} onPress={()=> navigation.pop()}/>
                </TouchableOpacity>
                <Text style={styles.textoTopo}>Categorias</Text>
            </View>
            <View style={styles.categorias}>
                <FlatList
                    data={initialCategories}
                    keyExtractor={initialCategories => initialCategories._id.toString()}
                    numColumns={3}
                    renderItem={({item}) => (<CategoryButton 
                                                title={item.titulo}
                                                cor={item.cor}
                                                comprimento={29}
                                                imagem={(require("../assets/brain.png"))}
                                                altura={19}
                                                onPress={"CategoryScreen"}
                                                params={ {"user" : route.params.user, "id" : item._id}}
                                                />)}
                    
                />
            </View>
        </>
    );
}

const styles = StyleSheet.create({
    categorias:{
        height: "100%",
        paddingLeft: "1.5%",
        backgroundColor: colors.white,
        paddingBottom: "10%",
    },
    textoTopo:{
        color: colors.green,
        fontSize: 18,
        fontWeight: "700",
        paddingLeft:"30%",
    },
    topo:{
        width: "100%",
        height: "6%",
        alignContent: "center",
        paddingHorizontal: "1.8%",
        borderColor: colors.grey,
        borderBottomWidth: 0.6,
        flexDirection: "row",
        alignItems: "center",
        backgroundColor: colors.white,
    },
})