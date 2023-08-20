import { createNativeStackNavigator } from "@react-navigation/native-stack";
import React from 'react';

import InterestScreen from '../../screens/InterestScreen';
import LoginScreen from '../../screens/LoginScreen';
import RegisterScreen from '../../screens/RegisterScreen';
import WelcomeScreen from '../../screens/WelcomeScreen';
import MainNavigator from "./MainNavigator";

const Stack = createNativeStackNavigator();
export default AuthNavigator = () => (
    <Stack.Navigator screenOptions={{
        headerShown: false,
      }}>
        <Stack.Screen name="WelcomeScreen" component={WelcomeScreen}/>
        <Stack.Screen name="LoginScreen" component={LoginScreen}/>
        <Stack.Screen name="RegisterScreen" component={RegisterScreen}/>
        <Stack.Screen name="MainContent" component={MainNavigator}/>
        <Stack.Screen name="InterestScreen" component={InterestScreen}/>
    </Stack.Navigator>
);
