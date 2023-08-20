import apiClient from "./client";

const endPoint = "/instituicoes";
const getInstituicoes = () => apiClient.get(endPoint+"/");
const getInstituicaoById = (id) => apiClient.get(endPoint+"/getInstituicaoById/"+id);


export default{
    getInstituicoes,
    getInstituicaoById,
}