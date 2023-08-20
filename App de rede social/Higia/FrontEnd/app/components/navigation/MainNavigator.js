import React from 'react';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { FontAwesome, Feather, FontAwesome5, MaterialCommunityIcons, Ionicons } from '@expo/vector-icons';

import colors from '../../config/colors';
import HomeScreen from '../../screens/HomeScreen';
import StackExploreNavigator from './StackExploreNavigator';
import StackHomeNavigator from './StackHomeNavigator';

const Tab = createBottomTabNavigator();
export default MainNavigator = ({route}) => (
    <Tab.Navigator screenOptions={{
        headerShown: false,
        tabBarActiveTintColor: colors.green,
    }}>
        <Tab.Screen name="Inicio" initialParams={route.params} component={StackHomeNavigator} options={{tabBarIcon: ({size, color})=> <FontAwesome name="home" size={size} color={color}/>}}/>
        <Tab.Screen name="Mapa" initialParams={route.params} component={HomeScreen} options={{tabBarIcon: ({size, color})=> <Feather name="map" size={size} color={color}/>}}/>
        <Tab.Screen name="Explorar" initialParams={route.params} component={StackExploreNavigator} options={{tabBarIcon: ({size, color})=> <FontAwesome5 name="compass" size={size} color={color}/>}}/>
        <Tab.Screen name="Grupos" initialParams={route.params} component={HomeScreen} options={{tabBarIcon: ({size, color})=> <MaterialCommunityIcons name="account-group-outline" size={size} color={color}/>}}/>
        <Tab.Screen name="Perfil" initialParams={route.params} component={HomeScreen} options={{tabBarIcon: ({size, color})=> <Ionicons name="ios-person-circle-outline" size={size} color={color}/>}}/>
    </Tab.Navigator>
);