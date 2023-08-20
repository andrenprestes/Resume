const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Mensagens"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const mensagensSchema = new mongoose.Schema({
    mensagem: String,
    data: {type: Date, default: Date.now},
    idGrupo: mongoose.ObjectId,
    idEnviou: mongoose.ObjectId,
});

const Mensagem = mongoose.model('mensagem', mensagensSchema);
const createMenssagem = async (idGrupo, idEnviou, mensagem) => {
    //idGrupo = mongoose.Types.ObjectId(idGrupo);
    //idEnviou = mongoose.Types.ObjectId(idEnviou);
    const mens = new Mensagem(
        {
            mensagem,
            idEnviou,
            idGrupo,
        }
    )
    const result = mens.save();
}

const getMessagesByUserId = async (id) => {
    return await Mensagem.find({
        idEnviou: id,
    });
}

const getMessagesByGroupId = async (id) => {
    return await Mensagem.find({
        idGrupo: id,
    });
}

const updateMensagem = async ({"id":id, "mensagem":mensagem, "idEnviou":idEnviou, "idGrupo":idGrupo}) =>{
    const result = await Mensagem.updateOne({_id: id}, {
        $set: {
            mensagem,
            idEnviou,
            idGrupo,
        }
    })
}

const deletarMensagem = async (id) =>{
    const result = await Mensagem.deleteOne({_id: id});
}

router.get('/getMessagesByGroupId/:id',(req, res) => {
    getMessagesByGroupId(req.params.id).then(result => res.send(result));
});
router.get('/getMessagesByUserId/:id',(req, res) => {
    getMessagesByUserId(req.params.id).then(result => res.send(result));
});
 
router.post('/createMessage',(req, res) => {
    const {idGrupo, idEnviou, mensagem} = req.body;
    createMenssagem(idGrupo, idEnviou, mensagem);
});

router.delete('/deleteMessage/:id',(req, res) => {
    deletarMensagem(req.params.id);
});

router.put('/updateMessage/:id',(req, res) => {
    const p = req.body;
    p["id"]=req.params.id;
    updateMensagem(p)
});

module.exports= router;
