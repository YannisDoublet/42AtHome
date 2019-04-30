import React from 'react';
import {Switch, Route} from 'react-router-dom'

import Home from './components/Home'
import Login from './components/Login'
import Layout from "./HOC/Layout";

const Routes = () => {
    return (
        <div>
            <Switch>
                <Route path={'/register'} exact component={Login}/>
                <Layout>
                    <Route path={'/'} exact component={Home}/>
                </Layout>
            </Switch>
        </div>
    );
};

export default Routes