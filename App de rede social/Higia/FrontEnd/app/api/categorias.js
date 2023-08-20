import apiClient from "./client";

const endPoint = "/categories";
const getCategories = () => apiClient.get(endPoint+"/");
const getCategoryById = (id) => apiClient.get(endPoint+"/getCategoryById/"+id);
const getCategoryByName = (Name) => apiClient.get(endPoint+"/getCategoryByName/"+Name);


export default{
    getCategories,
    getCategoryById,
    getCategoryByName,
}