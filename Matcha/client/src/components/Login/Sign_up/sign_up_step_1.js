import React, {Component} from 'react'
import {CSSTransition} from "react-transition-group"

class SignUpStep1 extends Component {

    state = {
        mounted: false,
        formData: {
            firstname: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'firstname',
                    placeholder: 'Firstname',
                },
                icon: 'fas fa-id-badge'
            },
            lastname: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'lastname',
                    placeholder: 'Lastname',
                },
                icon: 'fas fa-address-card'
            },
            age: {
                element: 'input',
                config: {
                    type: 'text',
                    name: 'age',
                    placeholder: 'Age',
                },
                icon: 'fas fa-birthday-cake'
            },
            gender: {
                element: 'select',
                type: 'select',
                name: 'Gender',
                options: [
                    'Man',
                    'Woman',
                    'Undefined'
                ]
            },
            sexuality: {
                element: 'select',
                type: 'select',
                name: 'Sexuality',
                options: [
                    'Heterosexual',
                    'Bisexual',
                    'Homosexual'
                ]
            }
        }
    };

    fetchInput = (data) => {
        const formArray = Object.keys(this.state.formData).map(key => this.state.formData[key]);
        const dataSettings = Object.keys(data).map(key => data[key]);
        return formArray.map((item, i) => {
            return (
                this.renderInput(item, dataSettings[i], i)
            );
        });
    };

    renderInput = (input, settings, i) => {
        let inputTemplate = null;
        const input_classes = [
            'sign_up_input',
            settings.touched && (settings.valid ? 'valid_input' : 'error_input')
        ].filter(v => !!v).join(' ');
        const icon_classes = [
            'input_icon',
            settings.touched && (settings.valid ? 'valid_icon' : 'error_icon')
        ].filter(v => !!v).join(' ');
        console.log(this.props);
        switch (input.element) {
            case('input'):
                inputTemplate = (
                    <CSSTransition key={i} timeout={1500} classNames="input_container" in={this.state.mounted}>
                        <div className={'input_container'}>
                            <input {...input.config} value={settings.value}
                                   className={input_classes} onChange={this.props.change}/>
                            <span className={icon_classes}>
                            <i className={input.icon}/>
                        </span>
                        </div>
                    </CSSTransition>
                );
                break;
            case('select'):
                inputTemplate = (
                    <CSSTransition key={i} timeout={1500} classNames="sign_up_select" in={this.state.mounted}>
                        <select className={'sign_up_select'}>
                            <option hidden selected>{input.name}</option>
                            {input.options ? input.options.map(item => (
                                <option>{item}</option>
                            )) : null}
                        </select>
                    </CSSTransition>);
                break;
            default:
                inputTemplate = null;
                break;
        }
        return inputTemplate;
    };

    componentDidMount() {
        this.setState({
            mounted: true
        })
    }

    render() {
        const settings = this.props;
        console.log(settings);
        return (
            <div className={'sign_up_container'}>
                {this.fetchInput(settings.data)}
                <div className={'button_container'}>
                    <CSSTransition timeout={1500} classNames="sign_up_button" in={this.state.mounted}>
                        <button className={'sign_up_button'}
                                onClick={() => this.props.handleStage(settings.stage)}>
                            Continue
                        </button>
                    </CSSTransition>
                </div>
            </div>
        );
    }
}

export default SignUpStep1;