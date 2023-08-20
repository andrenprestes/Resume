import * as Location from "expo-location";
import  {useEffect, useState} from 'react';

export default useLocation = () => {
    const [location, setLocation] = useState();

    const getLocation = async () =>{
        try {
            const resultLocation = await Location.requestForegroundPermissionsAsync();
            if( !resultLocation.granted)
                alert('É preciso permitir o acesso para o funcionamento de todas as funções do Aplicativo!');
            const {coords: {latitude, longitude}} = await Location.getLastKnownPositionAsync();
            setLocation({latitude, longitude});
            
        } catch (error) {
            console.log(error);
        }
    }

    useEffect(() => {
        getLocation();
    }, []);

    return location;
};