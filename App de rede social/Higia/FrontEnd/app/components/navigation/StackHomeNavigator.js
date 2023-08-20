import React from 'react';
import { createNativeStackNavigator } from '@react-navigation/native-stack';

import CategoriesScreen from '../../screens/CategoriesScreen';
import CategoryScreen from '../../screens/CategoryScreen';
import HomeScreen from '../../screens/HomeScreen';
import MessagesScreen from '../../screens/MessagesScreen';
import NotificationsScreen from '../../screens/NotificationsScreen';
import EventoScreen from '../../screens/EventoScreen';
import GrupoScreen from '../../screens/GrupoScreen';
import LiveScreen from '../../screens/LiveScreen';
import ArtigoScreen from '../../screens/ArtigoScreen';
import CreateContentScreen from '../../screens/CreateContentScreen';

const StackHome = createNativeStackNavigator();
export default StackHomeNavigator = ({route}) => (
    <StackHome.Navigator screenOptions={{
        headerShown: false,
      }}>
        <StackHome.Screen name="HomeScreen" initialParams={route.params.params} component={HomeScreen}/>
        <StackHome.Screen name="CategoryScreen" component={CategoryScreen}/>
        <StackHome.Screen name="CategoriesScreen" component={CategoriesScreen}/>
        <StackHome.Screen name="MessagesScreen" component={MessagesScreen}/>
        <StackHome.Screen name="NotificationsScreen" component={NotificationsScreen}/>
        <StackHome.Screen name="CreateContentScreen" component={CreateContentScreen}/>
        <StackHome.Screen name="Evento" component={EventoScreen}/>
        <StackHome.Screen name="Grupo" component={GrupoScreen}/>
        <StackHome.Screen name="Live" component={LiveScreen}/>
        <StackHome.Screen name="Artigo" component={ArtigoScreen}/>
    </StackHome.Navigator>
);