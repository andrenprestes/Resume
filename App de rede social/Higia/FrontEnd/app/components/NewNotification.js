import React from 'react';
import { View, Dimensions, Text} from 'react-native';

import colors from '../config/colors';

export default function NewNotification({tamanho, numero, cor, corFont, top, right}) {
    if (numero == 0){
        return (
            <View></View>
        );
    }
    if (!numero){
        return (
            <View style={[{
                backgroundColor: colors[cor],
                width: Dimensions.get("window").width*tamanho/100,
                aspectRatio: 1,
                borderRadius: Dimensions.get("window").width*tamanho/200,
            }, {
                top: top,
                right: right,
            }]}>
                
            </View>
        );
    }
    if (numero > 99){
        numero = "99+";
    }
    return (
        <View style={[{
            backgroundColor: colors[cor],
            height: Dimensions.get("window").height*tamanho/100,
            aspectRatio: 1.5,
            borderRadius: Dimensions.get("window").height*tamanho/200,
        }, {top: top,
            right: right}]}>
            <Text style={{
                fontSize: 9,
                color: colors[corFont],
                textAlign: "center",
            }}>{numero}</Text>
        </View>
    );
}
 
