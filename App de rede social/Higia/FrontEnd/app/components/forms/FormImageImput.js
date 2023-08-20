import React from 'react';
import { View, StyleSheet } from 'react-native';
import { useFormikContext } from 'formik';

import AddImage from '../AddImage';

export default function FormImageImput({name, ...otherProps}) {
    const { setFieldValue, values} = useFormikContext();
    return (
        <AddImage imageUri={values[name]}
                  onChange={uri => setFieldValue(name, uri)}
                  {...otherProps}/>
    );
}

const styles = StyleSheet.create({
    container:{

    },
})