import React from 'react';
import {Switch, Route} from 'react-router-dom'

import Home from './components/Home'
import Login from './components/Login'
import Profile from './components/Profile'
import Layout from "./HOC/Layout";

const Routes = () => {
    return (
        <Switch>
            <Route path={'/register'} exact component={Login}/>
            <Layout>
                <Route path={'/'} exact component={Home}/>
                <Route path={'/profile'} exact component={Profile} />
            </Layout>
        </Switch>
    );
};

export default Routes