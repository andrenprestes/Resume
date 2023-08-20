import apiClient from "./client";

const endPoint = "/messages";
const getMessagesByGroupId = (GroupId) => apiClient.get(endPoint+"/getMessagesByGroupId/"+GroupId);


export default{
    getMessagesByGroupId,
}