import React from 'react';
import { Button } from 'react-native';
import { useFormikContext } from 'formik';
import { useNavigation } from '@react-navigation/native';

export default function SubmitButtom({path, ...otherProps}) {
    const {handleSubmit} = useFormikContext();
    
    return (
        <Button onPress={handleSubmit} {...otherProps}/>
    );
}