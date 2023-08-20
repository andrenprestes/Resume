const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Promocoes"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const promocoesSchema = new mongoose.Schema({
    categorias: [mongoose.ObjectId],
    estabelecimento: mongoose.ObjectId,
    imagem: String,
    instituicao: mongoose.ObjectId,
    titulo: String,
    validade: Date,
});

const Promocao = mongoose.model('promocao', promocoesSchema);
const createPromocao = async (categorias, estabelecimento, imagem, instituicao, titulo, validade) =>{

    //categorias = categorias.map(x => mongoose.Types.ObjectId(x))
    //estabelecimento = mongoose.Types.ObjectId(estabelecimento);
    //instituicao = mongoose.Types.ObjectId(instituicao);
    const promocao = new Promocao(
        {
            categorias,
            estabelecimento,
            imagem,
            instituicao,
            titulo,
            validade,
        }
    )
    const result = await promocao.save();
};

const getPromocoes = async () => {
    return await Promocao.find();
}

const updatePromocao = async ({"id": id, "categorias":categorias, "estabelecimento":estabelecimento, "imagem":imagem, "instituicao":instituicao, "titulo":titulo, "validade":validade}) =>{
    const result = await Promocao.updateOne({_id: id}, {
        $set: {
            categorias,
            estabelecimento,
            imagem,
            instituicao,
            titulo,
            validade,
        }
    })
}

const deletarPromocao = async (id) =>{
    const result = await Promocao.deleteOne({_id: id});
}

router.get('/',(req, res) => {
    getPromocoes().then(result => res.send(result));
});

router.post('/createPromocao',(req, res) => {
    const {categorias, estabelecimento, imagem, instituicao, titulo, validade} = req.body;
    createPromocao(categorias, estabelecimento, imagem, instituicao, titulo, validade);
});

router.delete('/deletePromocao/:id',(req, res) => {
    deletarPromocao(req.params.id);
});

router.put('/updatePromocao/:id',(req, res) => {
    const p = req.body;
    p["id"]=req.params.id
    updatePromocao(p);
});

module.exports= router;