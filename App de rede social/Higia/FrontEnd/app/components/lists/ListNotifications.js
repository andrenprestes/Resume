import React from 'react';
import { View, StyleSheet, Dimensions, Text, TouchableHighlight} from 'react-native';
import moment from 'moment';
import { GestureHandlerRootView, Swipeable } from 'react-native-gesture-handler';

import colors from '../../config/colors';

export default function ListNotifications({tipo, conteudo, data, criado, onPress, renderRightActions}) {
    
    function texto(){
        var now = new Date();
        var ms = moment(data,"DD/MM/YYYY HH:mm").diff(moment(now,"DD/MM/YYYY HH:mm"));
        var d = moment.duration(ms);
        if (Math.floor(d.asHours()) <= 0){
            if (moment.utc(ms).format(" mm") > 0 && Math.floor(d.asHours()) == 0){
                return" vai começar em "+ moment.utc(ms).format(" m") + " minutos!";
            }
            ms = moment(now,"DD/MM/YYYY HH:mm").diff(moment(data,"DD/MM/YYYY HH:mm"));
            d = moment.duration(ms);
            return " começou a " + moment.utc(ms).format(" m") + " minutos!";
        } else if (Math.floor(d.asHours()) > 0){
            return " vai começar em " + Math.floor(d.asHours()) + " horas e " + moment.utc(ms).format(" m") + " minutos!";
        }
    }
    return (
        <GestureHandlerRootView>
            <Swipeable renderRightActions={renderRightActions}>
                <TouchableHighlight underlayColor={colors.light} onPress={onPress}>
                    <View style={styles.conteiner}>
                        <View style={styles.conteudo} >
                            <Text numberOfLines={2} style={styles.titulo}>A(O) {tipo} <Text style={styles.nome}>{conteudo}</Text> {texto()}</Text>
                        </View>
                        <View style={styles.conteudoData}>
                            <Text numberOfLines={1} style={styles.texto}>{criado}</Text>
                        </View>
                    </View>
                </ TouchableHighlight>
            </Swipeable>
        </GestureHandlerRootView>
    );
}

const styles = StyleSheet.create({
    conteudo: {
        width: Dimensions.get("window").width*0.93,
        height: Dimensions.get("window").height*0.055,
    },
    conteudoData: {
        width: Dimensions.get("window").width*0.93/2,
        height: Dimensions.get("window").height*0.025,
        alignSelf: "flex-end",
        alignItems: "flex-end",
    },
    conteiner:{
        width: Dimensions.get("window").width,
        height: Dimensions.get("window").height*0.11,
        paddingHorizontal: Dimensions.get("window").width*0.035,
        paddingVertical: Dimensions.get("window").width*0.03,
        alignItems: "center",
    },
    nome:{
        color: colors.purple,
        fontWeight: "500",
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