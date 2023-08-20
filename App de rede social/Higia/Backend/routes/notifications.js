const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Notificações"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const notificacoesSchema = new mongoose.Schema({
    conteudoId: mongoose.ObjectId,
    data: {type: Date, default: Date.now},
});

const Notificacao = mongoose.model('notificacao', notificacoesSchema);
const createNotification = async (conteudoId) => {
    const notificacoes = new Notificacao(
        {
            conteudoId,
        }
    ) 
    const result = notificacoes.save();
};

const getNotificacaoByConteudoId = async (id) => {
    return await Notificacao.find(
        {
            conteudoId: id,
        }
    );
}

const updateNotification = async ({"id": id, "data": data, "conteudoId":conteudoId}) =>{
    const result = await Notificacao.updateOne({_id: id}, {
        $set: {
            conteudoId,
            data,
        }
    })
}

const deletarNotificacao = async (id) =>{
    const result = await Notificacao.deleteOne({_id: id});
}

router.get('/getNotificationsByConteudoId/:id',(req, res) => {
    getNotificacaoByConteudoId(req.params.id).then(result => res.send(result));
});
 
router.post('/createNotification',(req, res) => {
    const {conteudoId} = req.body;
    createNotification(conteudoId);
});

router.delete('/deleteNotification/:id',(req, res) => {
    deletarNotificacao(req.params.id);
});

router.put('/updateNotification/:id',(req, res) => {
    const p = req.body;
    p["id"] = req.params.id
    updateNotification(p);
});

module.exports= router;