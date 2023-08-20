const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Estabelecimentos"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const estabelecimentoSchema = new mongoose.Schema({
    nome: String,
    conteudo: String,
    categorias: [mongoose.ObjectId],
    latitude: Number,
    longitude: Number,
});

const Estabelecimento = mongoose.model('estabelecimento', estabelecimentoSchema);
const createEstabelecimento = async (nome, conteudo, categorias, latitude, longitude) =>{

    const es = new Estabelecimento(
        {
            nome,
            conteudo,
            categorias,
            latitude,
            longitude
        }
    );
    const result = await es.save();
};

const getEstabelecimento = async () => {
    return await Estabelecimento.find();
}

const getEstabelecimentoByName = async (nome) => {
    return await Estabelecimento.find(
        {
            nome: nome,
        }
    );
}

const getEstabelecimentoById = async (id) => {
    return await Estabelecimento.find(
        {
            _id: id,
        }
    );
}

const updateEstabelecimento = async ({"id": id, "categorias":categorias, "conteudo":conteudo, "latitude":latitude, "longitude":longitude, "nome":nome}) =>{
    const result = await Estabelecimento.updateOne({_id: id}, {
        $set: {
            nome,
            conteudo,
            categorias,
            latitude,
            longitude
        }
    })
}

const deletarEstabelecimento = async (id) =>{
    const result = await Estabelecimento.deleteOne({_id: id});
}

router.get('/getEstabelecimentoByName/:name',(req, res) => {
    getEstabelecimentoByName(req.params.name).then(result => res.send(result));
});
router.get('/getEstabelecimentoById/:id',(req, res) => {
    getEstabelecimentoById(req.params.id).then(result => res.send(result));
});
router.get('/',(req, res) => {
    getEstabelecimento().then(result => res.send(result));
});

router.post('/createEstabelecimento',(req, res) => {
    const {nome, conteudo, categorias, latitude, longitude} = req.body;
    createEstabelecimento(nome, conteudo, categorias, latitude, longitude);
});

router.delete('/deleteEstabelecimento/:id',(req, res) => {
    deletarEstabelecimento(req.params.id);
});

router.put('/updateEstabelecimento/:id',(req, res) => {
    const p = req.body;
    p["id"]=req.params.id
    updateEstabelecimento(p);
});

module.exports= router;