import React from 'react';
import { useFormikContext } from 'formik';

import { AppPicker } from '../picker';
import  ErrorBox  from './ErrorBox';

export default function AppFormPicker({itens, name, placeholder, ...otherProps}) {
    const {errors, setFieldValue, touched, values} = useFormikContext();
    return (
        <>
            <AppPicker
                itens={itens}
                onSelectedItem={(item) => setFieldValue(name, item)}
                placeholder={placeholder}
                selectedItem={values[name]}
                {...otherProps}/>
            {touched[name] && <ErrorBox text={errors[name]}/>}
        </>
    );
}