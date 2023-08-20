const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Instituições"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const instituicoesSchema = new mongoose.Schema({
    titulo: String,
    imagem: String,
});

const Instituicao = mongoose.model('instituicao', instituicoesSchema);
const createInstituicao = async (titulo, urlImagem) =>{
    const instituicao = new Instituicao(
        {
            titulo,
            imagem: urlImagem,
        },
    );
    const result = await instituicao.save();
};

const getInstituicoes= async () => {
    return await Instituicao.find();
}

const getInstituicaoById = async (id) => {
    return await Instituicao.find({
        _id: id,
    });
}

const updateInstituicao = async ({"id":id, "titulo":titulo, "imagem":imagem}) =>{
    const result = await Instituicao.updateOne({_id: id}, {
        $set: {
            titulo, 
            imagem
        }
    })
}

const deletarInstituicao = async (id) =>{
    const result = await Instituicao.deleteOne({_id: id});
}

router.get('/getInstituicaoById/:id',(req, res) => {
    getInstituicaoById(req.params.id).then(result => res.send(result));
});
router.get('/',(req, res) => {
    getInstituicoes().then(result => res.send(result));
});

router.post('/createInstituicao',(req, res) => {
    const {titulo, urlImagem} = req.body
    createInstituicao(titulo, urlImagem);
});

router.delete('/deleteInstituicao/:id',(req, res) => {
    deletarInstituicao(req.params.id);
});

router.put('/updateInstituicao/:id',(req, res) => {
    const p = req.body;
    p["id"]=req.params.id;
    updateInstituicao(p);
});

module.exports= router;