import React from 'react';
import { Image, View, StyleSheet, Dimensions, Text, TouchableHighlight} from 'react-native';
import { GestureHandlerRootView, Swipeable } from 'react-native-gesture-handler';

import NewNotification from '../NewNotification';
import colors from '../../config/colors';

export default function ListMessages({nome, imagem, conteudo, data, numeroDeMensagens, onPress, renderRightActions}) {
    return (
        <GestureHandlerRootView>
            <Swipeable renderRightActions={renderRightActions}>
                <TouchableHighlight underlayColor={colors.light} onPress={onPress}>
                    <View style={styles.conteiner}>
                        <Image style={styles.image} source={{
                            uri: imagem,
                        }}/>
                        <View style={styles.conteudo} >
                            <Text numberOfLines={1}>{nome}</Text>
                            <Text numberOfLines={1} style={styles.texto}>{conteudo}</Text>
                        </View>
                        <View style={styles.conteudoData}>
                            <Text numberOfLines={1} style={[styles.texto]}>{data}</Text>
                            <NewNotification tamanho="1.9"
                                        numero={numeroDeMensagens}
                                        cor="purple"
                                        corFont="white"/>
                        </View>
                    </View>
                </ TouchableHighlight>
            </Swipeable>
        </GestureHandlerRootView>
    );
}

const styles = StyleSheet.create({
    conteudo: {
        width: Dimensions.get("window").width*0.54,
        height: Dimensions.get("window").height*0.06,
    },
    conteudoData: {
        alignItems: "flex-end",
        width: Dimensions.get("window").width*0.7,
        height: Dimensions.get("window").height*0.06,
        paddingRight: "44%"
    },
    conteiner:{
        width: Dimensions.get("window").width,
        height: Dimensions.get("window").height*0.09,
        flexDirection: "row",
        paddingTop: Dimensions.get("window").width*0.035,
    },
    image:{
        marginHorizontal: Dimensions.get("window").width*0.035,
        width: Dimensions.get("window").width*0.12,
        aspectRatio: 1,
        borderRadius: Dimensions.get("window").width*0.12/2,
        borderColor: colors.black,
        borderWidth: 1,
        justifyContent: "center",
    },
    texto:{
        color: colors.darkGrey,
        fontSize: 12,
    },
    titulo:{
        color: colors.dark,
        fontWeight: "500",
    }
})
