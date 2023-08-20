import React from 'react';
import { View, Dimensions} from 'react-native';
import { AntDesign } from '@expo/vector-icons'; 

import colors from '../config/colors';

export default function Check({tamanho, cor, top, right}) {
   
    return (
            <AntDesign style={[{
            top: top,
            right: right,
        }]} name="checkcircle" size={tamanho} color={colors[cor]} />
    );
}