import React, { useEffect, useState } from 'react';
import { NavigationContainer } from '@react-navigation/native';
import navigationTheme from './app/components/navigation/navigationTheme';

import AuthNavigator from './app/components/navigation/AuthNavigator';


export default function App() {

    return (
        <>
        <NavigationContainer theme={navigationTheme}>
            <AuthNavigator/>
        </NavigationContainer>
        </>
    );
}