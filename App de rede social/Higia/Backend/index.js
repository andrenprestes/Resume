const express = require('express');
const helmet = require('helmet');
const Joi = require('joi');

const users = require('./routes/users')
const notifications = require('./routes/notifications');
const messages = require('./routes/messages');
const instituicoes = require('./routes/instituicoes');
const conteudos = require('./routes/conteudos');
const categories = require('./routes/categories');
const estabelecimentos = require('./routes/estabelecimentos');
const promocoes = require('./routes/promocoes');

const app = express();
app.use(express.json());
app.use(helmet());

app.use("/api/users", users);
app.use("/api/notifications", notifications);
app.use("/api/messages", messages);
app.use("/api/instituicoes", instituicoes);
app.use("/api/conteudos", conteudos);
app.use("/api/categories", categories);
app.use("/api/estabelecimentos", estabelecimentos);
app.use("/api/promocoes", promocoes);

const port = process.env.PORT || 9000;
app.listen(port, ()=> console.log(`LIstening from port ${port}`))