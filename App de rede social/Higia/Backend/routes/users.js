const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Users"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const userSchema = new mongoose.Schema({
    categorias: [mongoose.ObjectId],
    email: String,
    imagem: String,
    instituicao: mongoose.ObjectId,
    nome: String,
    senha: String,
    grupos: [mongoose.ObjectId],
    eventos: [mongoose.ObjectId],
    lives: [mongoose.ObjectId],
    artigos: [mongoose.ObjectId],
});

const User = mongoose.model('user', userSchema);

const createUser = async (categorias, email, imagem, instituicao, nome, senha, grupos, eventos, lives, artigos) =>{

    //categorias = mongoose.Types.ObjectId.apply(categorias);
    //instituicao = mongoose.Types.ObjectId(instituicao);
    const user = new User({
        categorias,
        email,
        imagem,
        instituicao,
        nome,
        senha,
        grupos,
        eventos,
        lives,
        artigos,
    });
    const result = await user.save();
};

const getUserByEmail = async (email, senha) => {
    const user = await User.find({
        email: email,
        senha: senha
    });

    return user;
}

const getUserById = async (id) => {
    const user = await User.find({
        _id: id,
    });

    return user;
}

const verifyEmail = async (email) => {
    const user = await User.find({
        email: email,
    });
    if (user.length == 0){
        return true
    }else
    return false;
}

const verifyContent = async (id, tipo, contentId) => {
    let user;
    switch(tipo){
        case "Evento":
            user = await User.find({
                _id: id,
                eventos: {$in: contentId},
            });
            if (user.length != 0){
                let aux = user[0].eventos;
                return {existe: true, lista: aux};
            } else {
                user = await User.find({
                    _id: id,
                });
                let aux = user[0].eventos;
                return {existe: false, lista: aux};
            }
            break;

        case "Artigo":
            user = await User.find({
                _id: id,
                artigos: {$in: contentId},
            });
            if (user.length != 0){
                let aux = user[0].artigos;
                return {existe: true, lista: aux};
            } else {
                user = await User.find({
                    _id: id,
                });
                let aux = user[0].artigos;
                return {existe: false, lista: aux};
            }
            break;

        case "Live":
            user = await User.find({
                _id: id,
                lives: {$in: contentId},
            });
            if (user.length != 0){
                let aux = user[0].lives;
                return {existe: true, lista: aux};
            } else {
                user = await User.find({
                    _id: id,
                });
                let aux = user[0].lives;
                return {existe: false, lista: aux};
            }
            break;

        case "Grupo":
            user = await User.find({
                _id: id,
                grupos: {$in: contentId},
            });
            if (user.length != 0){
                let aux = user[0].grupos;
                return {existe: true, lista: aux};
            } else {
                user = await User.find({
                    _id: id,
                });
                let aux = user[0].grupos;
                return {existe: false, lista: aux};
            }
            break;
    }
}

const updateUser = async ({"id": id, "categorias":categorias, "email":email, "imagem":imagem, "instituicao":instituicao, "nome":nome, "senha":senha, "grupos":grupos, "eventos":eventos, "lives":lives, "artigos":artigos}) =>{
    const result = await User.updateOne({_id: id}, {
        $set: {
            categorias,
            email,
            imagem,
            instituicao,
            nome,
            senha,
            grupos,
            eventos,
            lives,
            artigos,
        }
    })
}

const deletarUser = async (id) =>{
    const result = await User.deleteOne({_id: id});
}

router.get('/getUserById/:id', (req, res) => {
    getUserById(req.params.id).then(result => res.send(result));
});

router.get('/getUserByEmail/:email/:senha', (req, res) => {
    getUserByEmail(req.params.email, req.params.senha).then(result => res.send(result));
});

router.get('/verifyContent/:id/:tipo/:contentId', (req, res) => {
    verifyContent(req.params.id, req.params.tipo, req.params.contentId).then(result => {
        res.send(result);
    });
});

router.get('/verifyEmail/:email', (req, res) => {
    verifyEmail(req.params.email).then(result => {
        res.send(result);
    });
});

router.post('/createUser', (req, res) => {
    const {categorias, email, imagem, instituicao, nome, senha, grupos, eventos, lives, artigos} = req.body;
    createUser(categorias, email, imagem, instituicao, nome, senha, grupos, eventos, lives, artigos).then((response)=>res.send(response));
});

router.delete('/deleteUser/:id',(req, res) => {
    deletarUser(req.params.id);
});

router.put('/updateUser/:id',(req, res) => {
    const p = req.body;
    p["id"]=req.params.id
    updateUser(p).then(()=>res.send(true));
});

module.exports= router;
