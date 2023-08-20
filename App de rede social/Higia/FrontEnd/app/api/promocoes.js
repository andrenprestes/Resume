import apiClient from "./client";

const endPoint = "/promocoes";
const getPromocoes = () => apiClient.get(endPoint+"/");

export default{
    getPromocoes,
}