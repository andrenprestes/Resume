import React from 'react';
import { createNativeStackNavigator } from '@react-navigation/native-stack';

import ContentScreen from '../../screens/ContentScreen';
import ExploreScreen from '../../screens/ExploreScreen';
import EventoScreen from '../../screens/EventoScreen';
import GrupoScreen from '../../screens/GrupoScreen';
import LiveScreen from '../../screens/LiveScreen';
import ArtigoScreen from '../../screens/ArtigoScreen';
import CreateContentScreen from '../../screens/CreateContentScreen';

const StackExplore = createNativeStackNavigator();
export default StackExploreNavigator = ({route}) => (
    <StackExplore.Navigator screenOptions={{
        headerShown: false,
      }}>
        <StackExplore.Screen name="ExploreScreen" initialParams={route.params.params} component={ExploreScreen}/>
        <StackExplore.Screen name="ContentScreen" component={ContentScreen}/>
        <StackExplore.Screen name="CreateContentScreen" component={CreateContentScreen}/>
        <StackExplore.Screen name="Evento" component={EventoScreen}/>
        <StackExplore.Screen name="Grupo" component={GrupoScreen}/>
        <StackExplore.Screen name="Live" component={LiveScreen}/>
        <StackExplore.Screen name="Artigo" component={ArtigoScreen}/>
    </StackExplore.Navigator>
);