import React, {useState} from 'react';
import { FlatList, View, StyleSheet, StatusBar, Dimensions, TouchableOpacity } from 'react-native';
import { Ionicons, FontAwesome } from '@expo/vector-icons';

import AddButton from '../components/AddButton';
import AppSearch from '../components/AppSearch';
import colors from '../config/colors';
import ExploreButtom from '../components/ExploreButtom';

const initialCategories = [
    {
        id: 1,
        tipo:"Artigos",
        cor:"purple", 
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
    {
        id: 2,
        tipo:"Grupos", 
        cor:"purple", 
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
    {
        id: 3,
        tipo:"Eventos", 
        cor:"purple",
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
    {
        id: 4,
        tipo:"Lives",
        cor:"purple",
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
    {
        id: 5,
        tipo:"Promoções", 
        cor:"purple", 
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
];

export default function ExploreScreen({navigation, route}) {

    const [messages, setMessages] = useState(initialCategories);
    const [searchMessage, setSearchMessage] = useState(initialCategories);
    return (
        <>
            <StatusBar style="auto" />
            <View style={styles.topo}>
                <TouchableOpacity activeOpacity={0.7}>
                    <Ionicons name="arrow-back" size={30} color={colors.green} onPress={()=> navigation.goBack()}/>
                </TouchableOpacity>
                <AppSearch categoria={"tipo"} messages={messages} setSearchMessage={setSearchMessage} titulo={"Explorar"}/>
            </View>
            <View style={styles.categorias}>
                <FlatList
                    data={searchMessage}
                    keyExtractor={searchMessage => searchMessage.id.toString()}
                    numColumns={2}
                    renderItem={({item}) => (<ExploreButtom 
                                                tipo={item.tipo}
                                                cor={item.cor}
                                                largura={47}
                                                altura={20}
                                                imagem={item.image}
                                                params={ {"user" : route.params._id, "id" : item.id}}
                                                />)}
                    
                />
            </View>
            <AddButton params={{"user" : route.params._id}}/>
        </>
    );
}

const styles = StyleSheet.create({
    categorias:{
        paddingBottom: "10%",
        marginLeft: "1.5%",
    },
    textoTopo:{
        color: colors.green,
        fontSize: 18,
        fontWeight: "700",
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