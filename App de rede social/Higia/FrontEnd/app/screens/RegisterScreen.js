import React, { useEffect, useState } from 'react';
import { StyleSheet, Text, View, ScrollView, StatusBar, TouchableOpacity, Dimensions} from 'react-native';
import { Ionicons } from '@expo/vector-icons';
import * as Yup from 'yup';


import colors from '../config/colors';
import {AppForm, AppFormField, SubmitButtom, AppFormPicker, FormImageImput} from '../components/forms';
import instituicoesApi from '../api/instituicoes';
import userApi from '../api/users';

const validationSchema = Yup.object().shape({
    email: Yup.string().required().email().label("Email"),
    senha: Yup.string().required().min(4).label("Senha"),
    nome: Yup.string().required().label("Nome"),
    instituicao: Yup.object().required().nullable().label("Instituição"),
})

export default function RegisterScreen({navigation, route}) {
    const [instituicoes, setInstituicoes] = useState();
    const [result, setResult] = useState();

    const loadInstituicoes = async () => {
        const instituicao = await instituicoesApi.getInstituicoes();
        setInstituicoes(instituicao.data);
    };

    const verifyUserEmail = (email, values) => {
        userApi.verifyEmail(email).then(response => {
            console.log(response.data);
            if (response.data.result){
                navigation.navigate("InterestScreen", {values});
                return;
            } else{
                alert("Email ja cadastrado!");
                return;
            }
        });
    } 

    useEffect(() => {
        loadInstituicoes();
    }, []);
    
    return (
    <>
        <StatusBar style="auto" />
        <View style={styles.topo}>
            <TouchableOpacity activeOpacity={0.7} onPress={()=> navigation.pop()}>
                <Ionicons name="arrow-back" size={30} color={colors.green} />
            </TouchableOpacity>
            <Text style={styles.textoTopo}>Criar conta</Text>
        </View>
        <ScrollView showsVerticalScrollIndicator={false} style={styles.conteudo}>
            <View style={styles.login}>
                <AppForm
                    initialValues={{email: "", senha: "", nome: "", instituicao: null, imagem: "https://i.kym-cdn.com/entries/icons/mobile/000/018/012/this_is_fine.jpg"}}
                    onSubmit={values => verifyUserEmail(values.email, values)}
                    validationSchema={validationSchema}>
                        <View style={styles.imagemPerfil}>
                            <FormImageImput 
                                name="imagem"/>
                        </View>
                        <View style={styles.boxInput}>
                            <AppFormPicker itens={instituicoes} name="instituicao" label={'Instituição'} placeholder={"Não selecionado"}/>
                            <AppFormField name={"nome"} label={'Nome'} placeholder={"João"}/>
                            <AppFormField name={"email"} label={'E-mail'} placeholder={"enxemplo@gmail.com"}/>
                            <AppFormField name={"senha"} label={"Senha"} placeholder={"Senha"} senha={true}/>
                        </View> 
                        <SubmitButtom color={colors.green} title='Concluir Cadastro'/>
                </AppForm>
                <View alignItems='center'>
                    <Text style={styles.cadastreSe} onPress={()=> navigation.navigate("LoginScreen")}>Já tem conta? Faça login</Text>
                </View>
            </View>
        </ScrollView>
    </>
  );
}

const styles = StyleSheet.create({
    boxInput:{
        marginBottom: 5,
        top: "-5%",
    },
    cadastreSe: {
        marginTop: "5%",
        color: colors.green,
    },
    conteudo:{
        paddingTop: "9%",
        height: 10,
        backgroundColor: colors.white,
    },
    imagemPerfil:{
        width: "100%",
        paddingBottom: "9%",
        alignItems: "center",
    },
    inicio: {
        flex: 1,
        backgroundColor: colors.green,
        alignItems: 'center',
        justifyContent: 'center',
    },
    login: {
        justifyContent: 'center',
        marginHorizontal: "10%",
    },
    textoTopo:{
        color: colors.green,
        fontSize: 18,
        fontWeight: "700",
        paddingLeft:"30%",
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
        backgroundColor: "white",
    },
});