import React from 'react';
import { View, Text, StyleSheet } from 'react-native';
import { MaterialIcons } from '@expo/vector-icons'; 
import colors from '../../config/colors';

export default function ErrorBox({text}) {
    return (
        <>
            {text 
            ? <>
                <View style={styles.box}>
                    <MaterialIcons name="error" size={20} color={colors.red} />
                    <Text style={styles.text}>{text}</Text>
                </View>
            </>
            : null}
        </>
    );
}

const styles = StyleSheet.create({
    box:{
        width: "100%",
        padding: 3,
        backgroundColor: colors.white,
        opacity: 0.7,
        flexDirection: "row",
    },
    text:{
        color: colors.black,
        paddingLeft: 5
    }
})