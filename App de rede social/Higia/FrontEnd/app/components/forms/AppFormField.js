import React from 'react';
import { useFormikContext } from 'formik';

import AppTextInput from '../AppTextInput';
import ErrorBox from './ErrorBox';

export default function AppFormField({name, ...otherProps}) {
    const {setFieldTouched, handleChange, errors, touched} = useFormikContext();
    return (
        <>
            <AppTextInput onBlur={()=> setFieldTouched(name)} 
                          onChangeText={handleChange(name)} 
                          {...otherProps}
                          />
            {touched[name] && <ErrorBox text={errors[name]}/>}
        </>
    );
}