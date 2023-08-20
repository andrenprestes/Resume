import React, { useState } from 'react';
import { StyleSheet, Text, View, TouchableWithoutFeedback, StatusBar, FlatList, Modal, Button, Dimensions} from 'react-native';
import { AntDesign } from '@expo/vector-icons'; 

import colors from '../../config/colors';
import  PickerItem  from './PickerItem';

export default function AppPicker({label, placeholder, itens, selectedItem, onSelectedItem}) {
    
    const [modalVisible, setModalVisible] = useState(false);

    return (
        <>
            <Text style={[styles.notSelected, {top: 10}]}>{label}</Text>
            <TouchableWithoutFeedback onPress={()=> setModalVisible(true)}>
                <View style={ [styles.inputNotSelected, {top: 10}]}>
                    <Text style={{color: colors.darkGrey}}>{selectedItem ? selectedItem.titulo : placeholder}</Text>
                    <AntDesign name="caretdown" size={17} color={colors.darkGrey} />
                </View>
            </TouchableWithoutFeedback>
            <Modal visible={modalVisible} animationType="slide">
                <StatusBar style="auto" />
                <Button color={colors.green} title='close' onPress={()=>setModalVisible(false)}/>
                <FlatList
                    data={itens}
                    keyExtractor={itens => itens.titulo}
                    renderItem={({item}) => (<PickerItem 
                                                label={item.titulo}
                                                onPress={()=>{setModalVisible(false)
                                                              onSelectedItem(item)}}
                                                />)}
                                                ItemSeparatorComponent={()=> <View style={{width: "100%", height: 1, backgroundColor: colors.grey, marginVertical: Dimensions.get("window").height*0.002}}/>}
                />
            </Modal>
        </>
    );
}

const styles = StyleSheet.create({
    inputNotSelected:{
        borderBottomColor: colors.black,
        borderBottomWidth: 1,
        height: 36,
        marginVertical: 9,
        flexDirection: "row",
        justifyContent: "space-between",
    },
    inputSelected:{
        borderBottomColor: colors.green,
        borderBottomWidth: 1,
        height: 36,
        marginVertical: 9,
        flexDirection: "row",
        justifyContent: "space-between",
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