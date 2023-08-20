import apiClient from "./client";

const endPoint = "/estabelecimentos";
const getEstabelecimentoById = (id) => apiClient.get(endPoint+"/getEstabelecimentoById/"+id);


export default{
    getEstabelecimentoById,
}