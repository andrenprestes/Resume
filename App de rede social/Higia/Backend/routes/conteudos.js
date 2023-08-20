const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');
const moment = require('moment');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Conteudo"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const conteudoSchema = new mongoose.Schema({
    categorias: [mongoose.ObjectId],
    tipo: String,
    imagem: String,
    instituicao: mongoose.ObjectId,
    titulo: String,
    conteudo: String,
    local: String,
    data: Date,
    latitude: Number,
    longitude: Number,
    criador: mongoose.ObjectId,
    dataCriacao: {type: Date, default: Date.now},
});

const Conteudo = mongoose.model('conteudo', conteudoSchema);
const createConteudo = async ({"categorias":categorias, "tipo":tipo, "imagem":imagem, "instituicao":instituicao, "titulo":titulo, "conteudo":conteudo, "local":local, "data":data, "latitude":latitude, "longitude":longitude, "criador":criador}) =>{

    const c = new Conteudo(
        {
            categorias,
            tipo,
            imagem,
            instituicao,
            titulo,
            conteudo,
            local,
            data,
            latitude,
            longitude,
            criador,
        }
    )
    const result = await c.save();
};

const getConteudoByTipo = async (tipo) => {
    return await Conteudo.find(
        {
            tipo: tipo,
        }
    );
}

const getConteudoByTipoCategory = async (tipo, idCategory) => {
    return await Conteudo.find(
        {
            tipo: tipo,
            categorias: {$in: idCategory},
        }
    );
}

const getConteudoById = async (id) => {
    return await Conteudo.find(
        {
            _id: id,
        }
    );
}

const newContent = async (timeDiference) => {
    return await Conteudo.find(
        {
            dataCriacao: {$gte:moment().subtract(timeDiference, "days"), $lt: Date.now()}
        }
    )
}

const gonnaHappen = async (timeDiference) => {
    return await Conteudo.find(
        {
            data: {$lt:moment().add(timeDiference, "days"), $gte: Date.now()}
        }
    )
}

const updateConteudo = async ({"id":id, "categorias":categorias, "tipo":tipo, "imagem":imagem, "instituicao":instituicao, "titulo":titulo, "conteudo":conteudo, "local":local, "data":data, "latitude":latitude, "longitude":longitude, "criador":criador}) =>{
    const result = await Conteudo.updateOne({_id: id}, {
        $set: {
            categorias, 
            tipo,
            imagem,
            instituicao,
            titulo,
            conteudo,
            local,
            data,
            latitude,
            longitude,
            criador,
        }
    })
}

const deletarConteudo = async (id) =>{
    const result = await Conteudo.deleteOne({_id: id});
}

router.get('/getConteudoById/:id',(req, res) => {
    getConteudoById(req.params.id).then(result => res.send(result));
});
router.get('/getConteudoByTipo/:tipo',(req, res) => {
    getConteudoByTipo(req.params.tipo).then(result => res.send(result));
});
router.get('/getConteudoByTipoCategory/:tipo/:idCategory',(req, res) => {
    getConteudoByTipoCategory(req.params.tipo, req.params.idCategory).then(result => res.send(result));
});
router.get('/newContent/:timeDiference', (req, res) => {
    newContent(req.params.timeDiference).then(result => res.send(result));
})
router.get('/gonnaHappen/:timeDiference', (req, res) => {
    gonnaHappen(req.params.timeDiference).then(result => res.send(result));
})

router.post('/createConteudo',(req, res) => {
    const p = req.body;
    createConteudo(p);
});

router.delete('/deleteConteudo/:id',(req, res) => {
    deletarConteudo(req.params.id);
});

router.put('/updateConteudo/:id',(req, res) => {
    const p = req.body;
    p["id"]=req.params.id;
    updateConteudo(p);
});

module.exports= router;