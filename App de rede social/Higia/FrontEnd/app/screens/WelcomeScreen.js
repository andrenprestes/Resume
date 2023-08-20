import React, { useEffect, useState } from 'react';
import { StyleSheet, Text, View, Image, SafeAreaView, Button, StatusBar, Platform} from 'react-native';

import colors from '../config/colors';

export default function WelcomeScreen({navigation}) {

  const [count, setCount] = useState(0);
  useEffect(()=>{
    const countTimer = setInterval(() => { count < 3 ? setCount((prevCount) => prevCount + 1) : null;}, 1000);
    return function cleanup() {clearInterval(countTimer);};
  });

  while(count < 3){
    return (
      <SafeAreaView style={styles.inicio}>
        <Image top='-7%' resizeMode='contain' source={require('../assets/logo-branco.png')}/>
        <StatusBar style="auto" />
      </SafeAreaView>
    );
  }
  return (
    <SafeAreaView style={styles.login}>
      <View  style={styles.logo}>
        <Image resizeMode='contain' source={require('../assets/logo.png')}/>
        <Text>Vamos nos cuidar juntos;)</Text>
      </View>
      <Button  onPress={()=>navigation.navigate("LoginScreen")} color={colors.green} title='Entrar'/>
      <View alignItems='center'>
        <Text style={styles.cadastreSe} onPress={()=> navigation.navigate("RegisterScreen")}>Cadastre-se</Text>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  cadastreSe: {
    marginTop: "5%",
    color: colors.green,
  },

  inicio: {
    flex: 1,
    backgroundColor: colors.green,
    alignItems: 'center',
    justifyContent: 'center',
    paddingTop: "20%",
  },

  login: {
    width: "100%",
    height: "100%",
    backgroundColor: colors.white,
    justifyContent: 'center',
    paddingHorizontal: "10%"
  },

  logo: {
    marginBottom:"22.5%",
    alignItems:'center',
    top: "-7%",
  },
});

