import React, { useState } from 'react';
import { StyleSheet, Text, View, Image, SafeAreaView, StatusBar, TouchableOpacity, ScrollView, Dimensions, Alert} from 'react-native';
import { Ionicons } from '@expo/vector-icons';
import * as Yup from 'yup';

import colors from '../config/colors';
import {AppForm, AppFormField, SubmitButtom} from '../components/forms';
import userApi from '../api/users';
import instituicoesApi from '../api/instituicoes';

const validationSchema = Yup.object().shape({
    email: Yup.string().required().email().label("Email"),
    senha: Yup.string().required().min(4).label("Senha"),
    
})

export default function LoginScreen({navigation}) {

    const [user, setUser] = useState();

    const run = async (email, senha) => {
        await userApi.getUserByEmail(email, senha).then(response => {
            var mess;
            if (response.data.length == 0){
                mess ="Email ou Senha errada!";
            } else{
                instituicoesApi.getInstituicaoById(response.data[0].instituicao).then(response2 => {
                    response.data[0].instituicao = response2.data[0];
                    navigation.navigate("MainContent", {params: response.data[0]})

                });
                return;
            }
            alert(mess);
        });
    }

    return (
    <>
        <StatusBar style="auto" />
        <View style={styles.topo}>
            <TouchableOpacity activeOpacity={0.7} onPress={()=> navigation.pop()}>
                <Ionicons name="arrow-back" size={30} color={colors.green} />
            </TouchableOpacity>
            <Text style={styles.textoTopo}>Entrar</Text>
        </View>
        <ScrollView showsVerticalScrollIndicator={false} style={styles.conteudo}>
            <View style={styles.logo}>
                <Image resizeMode='contain' source={require('../assets/logo.png')}/>
            </View>
            <SafeAreaView style={styles.login}>
                <AppForm
                    initialValues={{email: "", senha: ""}}
                    onSubmit={values => run(values.email, values.senha)}
                    validationSchema={validationSchema}>
                        <View style={styles.boxInput}>
                            <AppFormField name={"email"} label={'E-mail'} placeholder={"enxemplo@gmail.com"}/>
                            <AppFormField name={"senha"} label={"Senha"} placeholder={"Senha"} senha={true}/>
                        </View>
                        <SubmitButtom color={colors.green} title='Entrar'/>
                </AppForm>
                <View alignItems='center'>
                    <Text style={styles.cadastreSe} onPress={()=> navigation.navigate("RegisterScreen")}>Ainda não tem conta? Cadastre-se</Text>
                </View>
            </SafeAreaView>
            <View style={styles.baixo}>
                <Text style={styles.textoBaixo} onPress={()=> console.log()}>Esqueceu sua senha?</Text>
            </View>
        </ScrollView>
    </>
  );
}

const styles = StyleSheet.create({
    baixo:{
        justifyContent: "flex-end",
        bottom: "3%",
    },
    boxInput:{
        top: "-15%",
    },
    cadastreSe: {
        marginTop: "5%",
        color: colors.green,
    },
    conteudo:{
        paddingTop: "10%",
        backgroundColor: colors.white,
    },
    login: {
        flex: 1,
        justifyContent: 'center',
        marginHorizontal: "10%",
        top: "-9%",
    },
    logo: {
        marginBottom:"22.5%",
        alignItems:'center',
        top: "4%",
    },
    textoBaixo: {
        textAlign: "center",
        color: colors.black,
        fontWeight: "700",
    },
    textoTopo:{
        color: colors.green,
        fontSize: 18,
        fontWeight: "700",
        paddingLeft:"35%",
    },
    topo:{
        width: "100%",
        height: Dimensions.get("window").height*0.06,
        alignContent: "center",
        paddingHorizontal: "1.8%",
        borderColor: colors.grey,
        borderBottomWidth: 0.6,
        flexDirection: "row",
        alignItems: "center",
        backgroundColor: colors.white,
    },
});