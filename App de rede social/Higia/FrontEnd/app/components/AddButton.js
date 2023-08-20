import React from 'react';
import { StyleSheet, TouchableOpacity} from 'react-native';
import {  AntDesign } from '@expo/vector-icons';

import colors from '../config/colors';
import { useNavigation } from '@react-navigation/native';

export default function AddButton({params}) {
    const navigation = useNavigation();
    return (
        <TouchableOpacity style={styles.add} activeOpacity={0.7} onPress={()=> navigation.navigate("CreateContentScreen", {params: params})}>
            <AntDesign color={colors.purple} name="pluscircle" size={50} />
        </TouchableOpacity>
    );
}

const styles = StyleSheet.create({
    add:{
        bottom: "2%",
        left: "84%",
        position: "absolute",
    },
})