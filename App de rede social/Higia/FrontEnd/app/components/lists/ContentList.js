import { useRoute } from '@react-navigation/native';
import React from 'react';
import { FlatList, View, StyleSheet } from 'react-native';
import colors from '../../config/colors';

import { CardContent, CardPromocao } from '../cards';

export default function ContentList({tipo, altura, lista, params}) {
    
    return (
        <View style={[styles.categorias, {height: altura,}]}>
            {tipo == "Promoções"
            ? <FlatList
                    data={lista}
                    keyExtractor={lista => lista._id.toString()}
                    renderItem={({item}) => <CardPromocao
                                                titulo={item.titulo}
                                                imagem={item.imagem}
                                                estabelecimento={item.estabelecimento}
                                                validade={item.validade}
                                                posicaoImg="-78%"
                                                posicaoCrown="1100%"
                                                tamanhoCard={93}
                                                />}
                /> 

            : <FlatList
                data={lista}
                keyExtractor={lista => lista._id.toString()}
                renderItem={({item}) => <CardContent 
                                                tipo={item.tipo}
                                                titulo={item.titulo} 
                                                imagem={item.imagem} 
                                                conteudo={item.conteudo} 
                                                local={item.local}
                                                posicaoImg="-78%"
                                                data={item.data}
                                                criador={ item.criador}
                                                tamanhoCard={93}
                                                onPress={item.tipo}
                                                params={ {"user" : params.user, "id" : item._id}}
                                                />}
                
            />}
        </View>
    );
}

const styles = StyleSheet.create({
    categorias:{
        paddingLeft: "3.5%",
        backgroundColor: colors.white,
    },
})
