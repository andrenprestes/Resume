import apiClient from "./client";

const endPoint = "/users";
const getUserByEmail = (email, senha) => apiClient.get(endPoint+"/getUserByEmail/"+email+"/"+senha);
const verifyEmail = (email) => apiClient.get(endPoint+"/verifyEmail/"+email);
const verifyContent = (id,tipo,contentId) => apiClient.get(endPoint+"/verifyContent/"+id+"/"+tipo+"/"+contentId);
const getUserById = (id) => apiClient.get(endPoint+"/getUserById/"+id);
const updateUser = (id, dados) => {return apiClient.put(endPoint+"/updateUser/"+id, dados);};
const createUser = dados => {return apiClient.post(endPoint+"/createUser", dados);};


export default{
    getUserByEmail,
    verifyEmail,
    verifyContent,
    createUser,
    getUserById,
    updateUser,
}