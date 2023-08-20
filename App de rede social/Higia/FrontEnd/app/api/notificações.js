import apiClient from "./client";

const endPoint = "/notifications";
const getNotificationsByConteudoId = (GroupId) => apiClient.get(endPoint+"/getNotificationsByConteudoId/"+GroupId);


export default{
    getNotificationsByConteudoId,
}