import React, {useState} from 'react';
import {Text, View, StyleSheet, TouchableOpacity, TextInput } from 'react-native';
import {  AntDesign, FontAwesome  } from '@expo/vector-icons';

import colors from '../config/colors';

export default function AppSearch({ messages, setSearchMessage, titulo, categoria, paddingLeftIcon, paddingLeftTitle}) {

    const [pressed, setPressed] = useState(false);
    const [text, setText] = useState('');
    
    const handleSearch = message => {
        setSearchMessage(messages.filter(m => m[categoria].includes(message)))
    }

    return (
        <>
            {!pressed 
            ?<> 
                {titulo && <Text style={[styles.textoTopo, {paddingLeft: paddingLeftTitle,}]}>{titulo}</Text>}
                <TouchableOpacity style={{paddingLeft: paddingLeftIcon}} activeOpacity={0.7}>
                    <FontAwesome name="search" size={25} color={colors.green} onPress={()=>setPressed(true)}/>
                </TouchableOpacity>
            </>
            : 
                <View style={styles.searchBox}>
                    <TextInput value={text} style={styles.search} onBlur={()=> setPressed(false)} onChangeText={value => {setText(value), handleSearch(value)}} placeholder="Search..."/>
                    <TouchableOpacity activeOpacity={0.7} onPress={()=>{setText(''), setSearchMessage(messages)}}>
                        <AntDesign style={styles.icon} name="closecircle" size={20} color={colors.grey} />
                    </TouchableOpacity>
                </View>
            }
        </>
    );
}

const styles = StyleSheet.create({
    icon:{
        justifyContent: "flex-end",
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
})