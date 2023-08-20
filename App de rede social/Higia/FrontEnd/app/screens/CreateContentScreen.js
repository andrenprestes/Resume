import React, { useEffect, useState } from 'react';
import { StyleSheet, Text, View, ScrollView, StatusBar, TouchableOpacity, Dimensions, Button, TouchableWithoutFeedback, FlatList, DatePickerIOSComponent} from 'react-native';
import { AntDesign, Ionicons } from '@expo/vector-icons';
import * as Yup from 'yup';
import DateTimePicker from '@react-native-community/datetimepicker';
import moment from 'moment';

import colors from '../config/colors';
import {AppFormField, SubmitButtom, AppFormPicker, FormImageImput} from '../components/forms';
import instituicoesApi from '../api/instituicoes';
import conteudosApi from '../api/conteudos';
import categoriasApi from '../api/categorias';
import { Formik } from 'formik';
import { ErrorBox } from '../components/forms';

const validationSchema = Yup.object().shape({
    titulo: Yup.string().required().label("Titulo"),
    tipo: Yup.object().required().nullable().label("Tipo"),
    conteudo: Yup.string().required().label("Conteudo"),
    categor: Yup.array().required().min(1).label("Categorias"),
})

const tipos = [
    {
        id: 1,
        titulo:"Artigos",
        cor:"purple", 
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
    {
        id: 2,
        titulo:"Grupos", 
        cor:"purple", 
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
    {
        id: 3,
        titulo:"Eventos", 
        cor:"purple",
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
    {
        id: 4,
        titulo:"Lives",
        cor:"purple",
        image: "https://www.clipartmax.com/png/full/19-199773_pinky-and-the-brain-clip-art-brain-pinky-and-the-brain-png.png",
    },
];


export default function CreateContentScreen({navigation, route}) {
    const [instituicoes, setInstituicoes] = useState();
    const [result, setResult] = useState();
    const [initialCategories, setInitialCategorias] = useState();
    const [categorias, setCategorias] = useState([]);
    const [cat, setCat] = useState([]);

    const [mode, setMode] = useState('date');
    const [show, setShow] = useState(false);

    const onChange = (event, selectedDate, values) => {
        const currentDate = selectedDate;
        values.date = currentDate;
        setShow(false);
    };

    const showMode = (currentMode) => {
        setShow(true);
        setMode(currentMode);
    };

    const showDatepicker = () => {
        showMode('date');
    };

    const showTimepicker = () => {
        showMode('time');
    };
    
    const loadInstituicoes = async () => {
        const response = await instituicoesApi.getInstituicoes();
        setInstituicoes(response.data);
    };

    const loadCategorias = async () => {
        const response = await categoriasApi.getCategories();
        setInitialCategorias(response.data);
        setCat(response.data)
    };

    const createContent = async (values, criador) => {
        await conteudosApi.createConteudo(
            {"categorias":values.categor, 
            "tipo":values.tipo.titulo.slice(0, -1), 
            "imagem":values.imagem, 
            "instituicao":values.instituicao == null ? null : values.instituicao._id, 
            "titulo":values.titulo, 
            "conteudo":values.conteudo, 
            "local":values.local, 
            "data":values.date, 
            "latitude":0, 
            "longitude":0, 
            "criador":criador}
        )
    };

    const run = (values, criador) => {
        createContent(values, criador);
        navigation.pop();
    };

    const addCat = (id, values) => {
        setCategorias(arr => [...arr, id])
        values["categor"] = [...values["categor"], id];
    }

    const remCat = (id, values) => {
        setCategorias(categorias.filter(q=> q!== id))
        values["categor"] = values["categor"].filter(q=> q!== id);
    }

    useEffect(() => {
        loadInstituicoes();
        loadCategorias();
    }, []);

    
    return (
    <>
        <StatusBar style="auto" />
        <View style={styles.topo}>
            <TouchableOpacity activeOpacity={0.7} onPress={()=> navigation.pop()}>
                <Ionicons name="arrow-back" size={30} color={colors.green} />
            </TouchableOpacity>
            <Text style={styles.textoTopo}>Criar conteúdo</Text>
        </View>
        <ScrollView showsVerticalScrollIndicator={false} >
            <View style={[styles.conteudo, styles.login]}>
                <Formik
                    initialValues={{date: new Date(moment(new Date()).subtract(3, "hours")),local: "", titulo: "", conteudo: "", tipo: null, instituicao: null, categor: categorias, imagem: "https://i.kym-cdn.com/entries/icons/mobile/000/018/012/this_is_fine.jpg"}}
                    onSubmit={values => run(values, route.params.user)}
                    validationSchema={validationSchema}>
                        {({values, errors, touched}) => 
                        (<>
                        <View style={styles.imagemPerfil}>
                            <FormImageImput 
                                name="imagem"
                                borderRadius={0}
                                tamanho="50%"/>
                        </View>
                        <View style={styles.boxInput}>
                            <AppFormPicker itens={tipos} name="tipo" label={'Tipos'} placeholder={"Não selecionado"}/>
                            <Text style={styles.texto}>Categorias</Text>
                            {cat.map(x=>(
                                <TouchableWithoutFeedback key={x._id.toString()} color={categorias.includes(x._id.toString())?colors.green:colors.grey} onPress={categorias.includes(x._id.toString()) ? ()=>remCat(x._id.toString(), values) :()=>addCat(x._id.toString(), values)}>
                                    <View style={[styles.botao, {backgroundColor: categorias.includes(x._id.toString())?colors.green:colors.grey}]}>
                                        <Text >{x.titulo}</Text>
                                        {categorias.includes(x._id.toString()) && <AntDesign  name="closecircleo" size={20} color={colors.purple} />}
                                    </View>
                                </TouchableWithoutFeedback>
                            ))}
                            {touched["categor"] && <ErrorBox text={errors["categor"]}/>}
                            <AppFormField name={"titulo"} label={'Titulo'} placeholder={"Conter-Strike"}/>
                            <AppFormField name={"conteudo"} label={'Conteudo'} placeholder={"Grupo do CSzinho com a rapaziada"}/>
                            {(values.tipo !== null && (values.tipo.titulo == "Grupos" || values.tipo.titulo == "Eventos")) &&  <AppFormPicker itens={instituicoes} name="instituicao" label={'Instituições'} placeholder={"Não selecionado"}/>}
                            {(values.tipo !== null && (values.tipo.titulo == "Grupos" || values.tipo.titulo == "Eventos")) &&  <AppFormField name={"local"} label={'Local'} placeholder={"CT XII -UFES"}/>}
                            {(values.tipo !== null && (values.tipo.titulo == "Lives" || values.tipo.titulo == "Eventos")) &&  
                            <View style={styles.data}>
                                <View style={{paddingBottom: 10}}>
                                    <Text style={styles.texto}>Data</Text>
                                    <Button color={colors.green} onPress={showDatepicker} title="Selecionar data" />
                                </View>
                                <View>
                                    <Text style={styles.texto}>Horário</Text>
                                    <Button color={colors.green} onPress={showTimepicker} title="Selecionar horario" />
                                </View>
                                <Text style={styles.texto}>Selecionado: {moment(values.date).format("DD/MM/YYYY HH:mm")}</Text>
                                {show && (
                                    <DateTimePicker
                                        testID="dateTimePicker"
                                        value={values.date}
                                        mode={mode}
                                        is24Hour={true}
                                        tim
                                        onChange={(event, selectedDate) => onChange(event, selectedDate, values)}
                                    />
                                )}
                            </View>
                            }
                        </View> 
                            <SubmitButtom color={colors.green} title='Criar'/>
                        </>)}
                </Formik>
            </View>
        </ScrollView>
    </>
  );
}

const styles = StyleSheet.create({
    botao:{
        margin: 2,
        paddingHorizontal: 20,
        borderRadius: 100,
        flexDirection: "row",
        alignItems: "center",
        justifyContent: "center",
        height: 40,
        justifyContent: 'space-between',
    },
    boxInput:{
        marginBottom: 5,
        top: "-5%",
    },
    data:{
        marginTop: 20,
    },
    cadastreSe: {
        marginTop: "5%",
        color: colors.green,
    },
    conteudo:{
        paddingBottom: "30%",
        backgroundColor: colors.white,
    },
    imagemPerfil:{
        width: "100%",
        paddingBottom: "15%",
        paddingTop: 20,
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
        paddingLeft:"25%",
    },
    texto:{
        color: colors.darkGrey,
        fontSize: 12,
        marginVertical: 10,
        textAlign: 'left'
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