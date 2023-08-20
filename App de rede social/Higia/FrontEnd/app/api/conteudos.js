import apiClient from "./client";

const endPoint = "/conteudos";
const getConteudoById = (id) => apiClient.get(endPoint+"/getConteudoById/"+id);
const newContent = (timeDiference) => apiClient.get(endPoint+"/newContent/"+timeDiference);
const gonnaHappen = (timeDiference) => apiClient.get(endPoint+"/gonnaHappen/"+timeDiference);
const getConteudoByTipoCategory = (tipo, idCategory) => apiClient.get(endPoint+"/getConteudoByTipoCategory/"+tipo+"/"+idCategory);
const getConteudoByTipo = (tipo) => apiClient.get(endPoint+"/getConteudoByTipo/"+tipo);
const createConteudo = (dados) => apiClient.post(endPoint+"/createConteudo", dados)

export default{
    getConteudoById,
    newContent,
    gonnaHappen,
    getConteudoByTipoCategory,
    getConteudoByTipo,
    createConteudo,
}