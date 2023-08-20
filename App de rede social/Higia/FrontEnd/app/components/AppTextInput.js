import React, { useEffect, useState } from 'react';
import { StyleSheet, Text, TextInput} from 'react-native';

import colors from '../config/colors';

export default function AppTextInput({label, placeholder, onChangeText, onBlur, senha}) {
    
    const [selecionado, setSelecionado] = useState(false);

    return (
        <>
            {!senha
            ? <>
                <Text style={selecionado ? [styles.selected, {top: 10}] : [styles.notSelected, {top: 10}]}>{label}</Text>
                <TextInput onFocus={()=>setSelecionado(true)} onBlur={()=>{setSelecionado(false), onBlur}} onChangeText={onChangeText} placeholder={placeholder} style={selecionado ? styles.inputSelected : styles.inputNotSelected}/>
              </>
            : <>
                <Text style={selecionado ? [styles.selected, {top: 10}] : [styles.notSelected, {top: 10}]}>{label}</Text>
                <TextInput onFocus={()=>setSelecionado(true)} onBlur={()=>{setSelecionado(false), onBlur}} secureTextEntry onChangeText={onChangeText} placeholder={placeholder} style={selecionado ? styles.inputSelected : styles.inputNotSelected}/>
             </>
            }
        </>
    );
}

const styles = StyleSheet.create({
    inputNotSelected:{
        borderBottomColor: colors.black,
        borderBottomWidth: 1,
        height: 48,
    },
    inputSelected:{
        borderBottomColor: colors.green,
        borderBottomWidth: 1,
        height: 48,
    },
    selected:{
        color: colors.green,
        fontSize: 12,
    },
    notSelected:{
        color: colors.darkGrey,
        fontSize: 12,
    },
    
});