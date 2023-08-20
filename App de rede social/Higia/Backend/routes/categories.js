const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');
const mongoose = require('mongoose');

const router = express.Router();
router.use(express.json());
router.use(helmet());

mongoose.connect('mongodb://192.168.15.23:27017/higiadata')
    .then(() => console.log("Connected to MongoDB - Categorias"))
    .catch(err => console.log("Could not connect to MongoDB...", err));

const categoriasSchema = new mongoose.Schema({
    titulo: String,
    imagem: String,
    cor: String,
});

const Categoria = mongoose.model('categoria', categoriasSchema);

const createCateories = async (titulo, cor, urlImagem) =>{
    const categorias = new Categoria(
        {
            titulo, 
            cor, 
            imagem: urlImagem,
        }
    );
    const result = await categorias.save();
};

const getCategories = async () => {
    const categories = await Categoria.find();
    return categories;
}

const getCategoryById = async (id) => {
    const category = await Categoria.find({
        _id: id,
    });
    return category;
}

const getCategoryByName = async (Name) => {
    const category = await Categoria.find({
        titulo: Name,
    });
    return category;
}

const updateCategory = async ({"id":id, "imagem":imagem, "cor":cor}) =>{
    const result = await Categoria.updateOne({_id: id}, {
        $set: {
            cor, 
            imagem
        }
    })
}

const deletarCategoria = async (id) =>{
    const result = await Categoria.deleteOne({_id: id});
}

router.get('/getCategoryById/:id', (req, res) =>{
    getCategoryById(req.params.id).then(result => res.send(result));
});

router.get('/getCategoryByName/:Name', (req, res) =>{
    getCategoryByName(req.params.Name).then(result => {
        res.send(result)
    });
});

router.get('/', (req, res) => {
    getCategories().then(result => {
        res.send(result);
    });
});

router.post('/createCategory',(req, res) => {
    const {titulo, cor, urlImagem} = req.body;
    createCateories(titulo, cor, urlImagem);
});

router.delete('/deleteCategory/:id',(req, res) => {
    deletarCategoria(req.params.id);
});

router.put('/updateCategory/:id',(req, res) => {
    const p = req.body;
    p["id"] = req.params.id;
    updateCategory(p);
});

module.exports= router;